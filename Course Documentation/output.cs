using System;
using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;

namespace CtoxService
{
    public class Ctox
    {
        private readonly string command;
        
        public Ctox(string command)
        {
            if (!File.Exists(command))
            {
                throw new ArgumentException("File doesn't exist. Check if it's compiled.");
            }

            this.command = command;
        }

        public string Parse(string content)
        {
            // Создание процесса, с перенаправленными стандартными потоками
            using var process = new Process();
            process.StartInfo.FileName = command;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;

            // Запуск процесса и запись в поток ввода
            process.Start();
            process.StandardInput.Write(content);

            // Закрытие потока ввода
            process.StandardInput.Close();

            // Закрытие процесса и сохранение вывода
            var result = process.StandardOutput.ReadToEnd();
            process.WaitForExit();

            return result;
        }

        public Task<string> ParseAsync(string content)
        {
            return Task.Run(() => Parse(content));
        }
    }
}

using System.Threading;
using Microsoft.AspNetCore.Builder;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;

namespace CtoxWebApp
{
    public static class ApplicationBuilderExtensions
    {
        private const int MaxRetries = 10;
        private const int RetryDelay = 5000;

        public static void EnsureConnected<T>(this IApplicationBuilder app)
            where T : DbContext
        {
            using var scope = app.ApplicationServices.CreateScope();
            var context = (T) scope.ServiceProvider.GetService(typeof(T));

            for (int i = 0; i < MaxRetries; i++)
            {
                if (context.IsConnected())
                {
                    return;
                }
                Thread.Sleep(RetryDelay);
            }

            throw new System.InvalidOperationException("Could not establish connection");
        }

        public static void EnsureMigrated<T>(this IApplicationBuilder app)
            where T : DbContext
        {
            using var scope = app.ApplicationServices.CreateScope();
            var context = (T) scope.ServiceProvider.GetService(typeof(T));
            context.Database.Migrate();
        }

        private static bool IsConnected(this DbContext context)
        {
            try 
            {
                _ = context.Database.ExecuteSqlRaw("SELECT 1");
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}

using System;

namespace CtoxWebApp.Attributes.Filters 
{
    public class AllowNoApi : Attribute
    {
    }
}

using System;
using System.Data.Entity;
using System.Linq;
using CtoxWebApp.DAL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Controllers;
using Microsoft.AspNetCore.Mvc.Filters;

namespace CtoxWebApp.Attributes.Filters
{
    public class ApiKey : Attribute, IActionFilter
    {
        public ApiKey()
        {
        }

        public string Roles { get; set; }

        public void OnActionExecuting(ActionExecutingContext context)
        {
            // ReSharper disable once PossibleNullReferenceException
            if ((context.ActionDescriptor as ControllerActionDescriptor)
                .MethodInfo
                .GetCustomAttributes(typeof(AllowNoApi), false)
                .FirstOrDefault() != null)
            {
                return;
            }

            if (!context.HttpContext.Request.Headers.ContainsKey("x-api-key"))
            {
                context.Result = new UnauthorizedObjectResult("No api key");
                return;
            }

            var dbContext = (AppDbContext)context.HttpContext.RequestServices.GetService(typeof(AppDbContext));

            var api = dbContext.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.Key.Equals(context.HttpContext.Request.Headers["x-api-key"]));

            if (api is null)
            {
                context.Result = new UnauthorizedObjectResult("No api key");
                return;
            }

            if (Roles is null || Roles.Length == 0)
            {
                return;
            }

            foreach (var role in Roles.Split(','))
            {
                if (api.User.Role.ToString().Equals(role))
                {
                    return;
                }
            }

            context.Result = new UnauthorizedObjectResult("No api key");
        }

        public void OnActionExecuted(ActionExecutedContext context)
        {
        }
    }
}

﻿#nullable enable
using System.ComponentModel.DataAnnotations;
using MimeKit;

namespace CtoxWebApp.Attributes.Validations
{
    public class EmailAttribute : ValidationAttribute
    {
        public override bool IsValid(object? value)
        {
            if (!(value is string vs))
            {
                return false;
            }

            return MailboxAddress.TryParse(vs, out MailboxAddress _);
        }
    }
}

﻿#nullable enable
using System;
using System.ComponentModel.DataAnnotations;

namespace CtoxWebApp.Attributes.Validations
{
    [Flags]
    public enum PasswordHas
    {
        None = 0,
        Uppercase = 1,
        Lowercase = 2,
        Digit = 4,
        Special = 8,
    }

    public class StrongPasswordAttribute : ValidationAttribute
    {
        private readonly PasswordHas props;
        
        public StrongPasswordAttribute(PasswordHas props)
        {
            this.props = props;
        }

        public override bool IsValid(object? value)
        {
            if (value is null)
            {
                return false;
            }

            var vs = value.ToString();
            if (vs is null)
            {
                return false;
            }

            return (Score(vs) & props) == props;
        }

        private PasswordHas Score(string value)
        {
            PasswordHas result = PasswordHas.None;
            foreach (var c in value)
            {
                if (!result.HasFlag(PasswordHas.Uppercase) && char.IsUpper(c))
                {
                    result |= PasswordHas.Uppercase;
                    continue;
                }
                
                if (!result.HasFlag(PasswordHas.Lowercase) && char.IsLower(c))
                {
                    result |= PasswordHas.Lowercase;
                    continue;
                }
                
                if (!result.HasFlag(PasswordHas.Digit) && char.IsDigit(c))
                {
                    result |= PasswordHas.Digit;
                    continue;
                }
                
                if (!result.HasFlag(PasswordHas.Special) && char.IsSymbol(c))
                {
                    result |= PasswordHas.Special;
                }
            }

            return result;
        }
    }
}

﻿#nullable enable
using System;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using CtoxWebApp.DAL;
using Microsoft.Extensions.DependencyInjection;

namespace CtoxWebApp.Attributes.Validations
{
    public class UniqueEmailAttribute : ValidationAttribute
    {
        protected override ValidationResult? IsValid(object? value, ValidationContext validationContext)
        {
            if (value is null)
            {
                return new ValidationResult(null);
            }

            var context = validationContext.GetService<AppDbContext>();
            var vs = value.ToString();

            if (context?.Users.FirstOrDefault(u => u.Email.Equals(vs, StringComparison.Ordinal)) != null)
            {
                return new ValidationResult(null);
            }
            
            return ValidationResult.Success;
        }
    }
}

﻿#nullable enable
using System;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using CtoxWebApp.DAL;
using Microsoft.Extensions.DependencyInjection;

namespace CtoxWebApp.Attributes.Validations
{
    public class UniqueUsernameAttribute : ValidationAttribute
    {
        protected override ValidationResult? IsValid(object? value, ValidationContext validationContext)
        {
            if (value is null)
            {
                return new ValidationResult(null);
            }

            var context = validationContext.GetService<AppDbContext>();
            var vs = value.ToString();

            if (context?.Users.FirstOrDefault(u => u.Username.Equals(vs, StringComparison.Ordinal)) != null)
            {
                return new ValidationResult(null);
            }
            
            return ValidationResult.Success;
        }
    }
}

using System;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;
using CtoxWebApp.Attributes.Filters;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.UserModel.Domain;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;

namespace CtoxWebApp.Controllers
{
    [ApiKey(Roles = "Admin")]
    [Route("/api/admin")]
    public class AdminApiController : ControllerBase
    {
        private const string ContentTypeJson = "application/json";
        private readonly AppDbContext context;

        public AdminApiController(AppDbContext context)
        {
            this.context = context;
        }

        [HttpGet("users")]
        public IActionResult GetUsers()
        {
            var users =
                from u in context.Users
                select new { 
                    u.Id, 
                    u.Username, 
                    u.Email, 
                    u.Confirmed, 
                    Role = u.Role.ToString() 
                    };

            return Content(JsonConvert.SerializeObject(users), ContentTypeJson);            
        }

        [HttpDelete("user")]
        public async Task<IActionResult> DeleteUser(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            context.Users.Remove(user);
            await context.SaveChangesAsync();
            return Ok();
        }

        [HttpGet("stat")]
        public IActionResult GetStat(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            var api = context.Apis.FirstOrDefault(a => a.UserId == id);
            var res = context.PasswordRestores.Where(r => r.UserId == id).Count();

            if (api is null)
            {
                return Content(JsonConvert.SerializeObject(new { HasKey = false, Restores = res }), ContentTypeJson);
            }

            var result = new {
                HasKey = true,
                Key = api.Key,
                LastUsed = api.LastUsed,
                Conversions = context.Conversions.Where(c => c.UserId == id).Count(),
                Restores = res
            };
            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }

        [HttpPut("confirmed")]
        public async Task<IActionResult> SetConfirmed(int? id, bool? confirmed)
        {
            if (id is null || confirmed is null)
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            user.Confirmed = (bool) confirmed;
            await context.SaveChangesAsync();

            return Ok();
        }

        [HttpPut("role")]
        public async Task<IActionResult> SetRole(int? id, Role? role)
        {
            if (id is null || role is null)
            {
                return BadRequest();
            }

            if (!Enum.IsDefined(typeof(Role), role))
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            user.Role = (Role) role;
            await context.SaveChangesAsync();

            return Ok();
        }

        [HttpGet("conversions")]
        public IActionResult GetConversions(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var conversions = context.Conversions
                .Where(c => c.UserId == id)
                .Select(c => new { c.Id, c.Time, Type = c.Type.ToString()});

            if (conversions.Count() == 0)
            {
                return NotFound();
            }    

            return Content(JsonConvert.SerializeObject(conversions), ContentTypeJson);
        }

        [HttpDelete("conversion")]
        public async Task<IActionResult> DeleteConversion(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var conversion = context.Conversions.FirstOrDefault(c => c.Id == id);
            if (conversion is null)
            {
                return NotFound();
            }

            context.Conversions.Remove(conversion);
            await context.SaveChangesAsync();
            return Ok();
        }

        [HttpGet("view")]
        public IActionResult ViewConversion(int? id, [FromServices] IStringCompressService compress)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var conversion = context.Conversions.FirstOrDefault(c => c.Id == id);
            if (conversion is null)
            {
                return NotFound();
            }

            var result = new {
                Initial = compress.Decompress(conversion.Initial),
                Result = compress.Decompress(conversion.Result)
            };

            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }
    }
}

using System;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;
using System.Xml.Linq;
using CtoxWebApp.Attributes.Filters;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Services.Implementations;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;

namespace CtoxWebApp.Controllers
{
    [ApiKey]   
    [Route("api")]
    public class ApiController : ControllerBase
    {
        private const string TestResultText = "<function>" +
                                              "<prototype> void test ( ) </prototype>" +
                                              "<body>" +
                                              "<expression hascalls = \"true\">" +
                                              "<funccall>" +
                                              "<name> printf </name>" +
                                              "<arguments>\"%s\\n\" , \"Hello from api!\" </arguments>" +
                                              "</funccall>" +
                                              "<text> printf ( \"%s\\n\" , \"Hello from api!\" ) </text>" +
                                              "</expression>" +
                                              "</body>" +
                                              "</function>";

        private const string ContentTypeJson = "application/json";
        private const string ContentTypeXml = "application/xml";
        private const string ApiKeyHeader = "x-api-key";

        private static readonly string TestResultJson = JsonConvert.SerializeXNode(XElement.Parse(TestResultText));

        private readonly AppDbContext context;
        private readonly RestrictionService restriction;
        private readonly IParseAsyncService parseAsync;
        private readonly IStringCompressService compress;

        public ApiController(AppDbContext context, RestrictionService restriction, IParseAsyncService parseAsync,
            IStringCompressService compress)
        {
            this.context = context;
            this.restriction = restriction;
            this.parseAsync = parseAsync;
            this.compress = compress;
        }

        [HttpGet("test")]
        public IActionResult Test(bool? json)
        {
            if (json != true)
            {
                return Content(TestResultText, ContentTypeXml);
            }

            return Content(TestResultJson, ContentTypeJson);
        }

        [Authorize]
        [AllowNoApi]
        [HttpGet("create")]
        public async Task<IActionResult> Create([FromServices] IHashService hash)
        {
            var user = context.Users.First(u => u.Username.Equals(HttpContext.User.Identity.Name));
            var api = context.Apis.FirstOrDefault(a => a.UserId == user.Id);

            if (api is null)
            {
                api = new Api
                {
                    Key = hash.GetRandom(),
                    LastUsed = DateTime.MinValue,
                    UserId = user.Id
                };

                context.Apis.Add(api);
            }
            else
            {
                api.Key = hash.GetRandom();
            }

            await context.SaveChangesAsync();
            return StatusCode(201, new {api.Key});
        }

        [HttpPost("parse")]
        public async Task<IActionResult> Parse(
            bool? json,
            [FromBody] ParseRequest request,
            [FromHeader(Name = ApiKeyHeader)] string key)
        {
            if (request is null
                || string.IsNullOrWhiteSpace(request.Data))
            {
                return BadRequest("Empty");
            }

            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));

            if (!restriction.IsAllowedTimeout(api))
            {
                return StatusCode(429, "Timeout");
            }

            if (!restriction.IsAllowedSize(api, request.Data.Length))
            {
                return StatusCode(413, "Size");
            }

            api.LastUsed = DateTime.Now;

            var parseResult = await parseAsync.ParseAsync(request.Data);
            if (json == true)
            {
                parseResult = JsonConvert.SerializeXNode(XElement.Parse(parseResult));
            }

            context.Conversions.Add(new Conversion
            {
                Initial = compress.Compress(request.Data),
                Result = compress.Compress(parseResult),
                Type = json == true ? ParseType.Json : ParseType.Xml,
                Time = api.LastUsed,
                UserId = api.UserId,
            });
            await context.SaveChangesAsync();

            return Content(parseResult, json == true ? ContentTypeJson : ContentTypeXml);
        }

        [HttpGet("history")]
        public IActionResult History(
            DateTime? day,
            bool? ascending,
            int? skip,
            int? limit,
            [FromHeader(Name = ApiKeyHeader)] string key)
        {
            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));

            var conversions = context.Conversions
                .Where(c => c.UserId == api.UserId);

            conversions = SearchConversions(conversions, day, ascending, skip, limit);

            var data = conversions.Select(c => new
            {
                c.Id,
                c.Time,
                c.Type
            });

            var result = new {Amount = data.Count(), Data = data};
            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }

        [HttpGet("view")]
        public IActionResult View(int? id, [FromHeader(Name = ApiKeyHeader)] string key)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));

            var conversion = context.Conversions.FirstOrDefault(c => c.Id == id);

            if (conversion is null || conversion.UserId != api.UserId)
            {
                return NotFound();
            }

            var result = new
            {
                Initial = compress.Decompress(conversion.Initial),
                Result = compress.Decompress(conversion.Result)
            };

            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }

        private IQueryable<Conversion> SearchConversions(
            IQueryable<Conversion> conversions,
            DateTime? day,
            bool? ascending,
            int? skip,
            int? limit)
        {
            if (day != null)
            {
                conversions = conversions.Where(c => c.Time.Date == ((DateTime) day).Date);
            }

            conversions = ascending == false ? 
                conversions.OrderByDescending(c => c.Time) : 
                conversions.OrderBy(c => c.Time);

            if (skip != null)
            {
                conversions = conversions.Skip((int) skip);
            }

            if (limit != null)
            {
                conversions = conversions.Take((int) limit);
            }

            return conversions;
        }
    }
}

﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.UserModel.Domain;
using CtoxWebApp.Models.UserModel.View;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace CtoxWebApp.Controllers
{
    public class AuthController : Controller
    {
        private const string LoginNotFilledErrorMessage =
            "Both username and password should be filled in. Please check your username and password and try again.";

        private const string LoginNotFoundErrorMessage =
            "We couldn't find an account matching the username and password you entered. Please check your username and password and try again.";

        private const string LoginNotConfirmedErrorMessage =
            "It seems like you didn't confirm your email address. Please make sure that you followed the link sent to your email.";

        private const string VerificationInvalidErrorMessage =
            "Invalid verification string. Please make sure you followed the link correctly.";

        private const string VerificationAgainErrorMessage = "Your email have been already confirmed.";
        private const string VerificationVerifiedInfoMessage = "Your email has been verified.";

        private const string RestoreInfoMessage =
            "If this email address was used to create an account, instructions to reset your password will be sent to you. Please check your email.";

        private const string ResetSuccessInfoMessage = "Password for specified user was successfully reset.";

        private readonly AppDbContext dbContext;
        private readonly IHashService hashService;
        private readonly IEmailSenderService sender;

        public AuthController(AppDbContext dbContext, IHashService hashService, IEmailSenderService sender)
        {
            this.dbContext = dbContext;
            this.hashService = hashService;
            this.sender = sender;
        }

        public IActionResult Login()
        {
            if (User.Identity.IsAuthenticated)
            {
                return RedirectToAction("Index", "Home");
            }

            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Login(UserLogin user)
        {
            if (user.Username is null || user.Password is null)
            {
                ViewData["error-message"] =
                    LoginNotFilledErrorMessage;
                return View();
            }

            var hash = hashService.GetHash(string.Concat(user.Username, hashService.GetHash(user.Password)));

            var result = dbContext.Users
                .FirstOrDefault(u => u.Username.Equals(user.Username, StringComparison.Ordinal) &&
                                     u.PasswordHash.Equals(hash, StringComparison.Ordinal));

            if (result is null)
            {
                ViewData["error-message"] =
                    LoginNotFoundErrorMessage;
                return View();
            }

            if (!result.Confirmed)
            {
                ViewData["error-message"] =
                    LoginNotConfirmedErrorMessage;
                return View();
            }

            await Authenticate(result);
            return RedirectToAction("Index", "Home");
        }

        public IActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Register(UserRegister user)
        {
            if (!ModelState.IsValid) return View(user);

            var registered = new User
            {
                Username = user.Username,
                Email = user.Email,
                PasswordHash =
                    hashService.GetHash(string.Concat(user.Username, hashService.GetHash(user.Password))),
                Confirmed = false,
                Role = Role.Regular,
            };

            dbContext.Users.Add(registered);
            await dbContext.SaveChangesAsync();

            if (User.Identity.IsAuthenticated)
            {
                await HttpContext.SignOutAsync(CookieAuthenticationDefaults.AuthenticationScheme);
            }

            await SendVerification(registered);

            return Redirect("Login");
        }

        public async Task<IActionResult> Verify(string verificationString)
        {
            if (string.IsNullOrWhiteSpace(verificationString))
            {
                return BadRequest();
            }

            if (User.Identity.IsAuthenticated)
            {
                await HttpContext.SignOutAsync();
            }

            var result = dbContext.UserVerifications
                .Include(v => v.User)
                .FirstOrDefault(v => v.Verification.Equals(verificationString, StringComparison.Ordinal));

            if (result is null)
            {
                ViewData["error-message"] =
                    VerificationInvalidErrorMessage;
                return View("Login");
            }

            if (result.User.Confirmed)
            {
                ViewData["error-message"] =
                    VerificationAgainErrorMessage;
                return View("Login");
            }

            result.User.Confirmed = true;
            await dbContext.SaveChangesAsync();

            ViewData["info-message"] = VerificationVerifiedInfoMessage;
            return View("Login");
        }

        public IActionResult Restore()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Restore(UserRestoreRequest user)
        {
            var result = dbContext.Users.FirstOrDefault(u => u.Email.Equals(user.Email));
            if (result != null)
            {
                var hash = hashService.GetRandom();
                dbContext.PasswordRestores.Add(new PasswordRestore
                {
                    UserId = result.Id,
                    Restore = hash,
                    Valid = true,
                });
                await dbContext.SaveChangesAsync();
                await sender.SendEmailAsync(result.Username, result.Email,
                    $"Someone tries to reset your password on CTOX.\nIf it were you, please follow the link https://localhost:5001/Reset/{hash}");
            }

            ViewData["info-message"] = RestoreInfoMessage;
            return View("Login");
        }

        public async Task<IActionResult> Reset(string resetString)
        {
            if (string.IsNullOrWhiteSpace(resetString))
            {
                return BadRequest();
            }

            if (User.Identity.IsAuthenticated)
            {
                await HttpContext.SignOutAsync();
            }

            var result = dbContext.PasswordRestores
                .Include(p => p.User)
                .FirstOrDefault(p => p.Restore.Equals(resetString));

            if (result is null || !result.Valid)
            {
                return BadRequest();
            }

            return View(new UserRestore {Restore = resetString});
        }

        [HttpPost]
        public async Task<IActionResult> Reset(UserRestore user)
        {
            if (!ModelState.IsValid) return View(user);
            var result = dbContext.PasswordRestores
                .Include(p => p.User)
                .FirstOrDefault(p => p.Restore.Equals(user.Restore));

            if (result is null || !result.Valid)
            {
                return BadRequest();
            }

            result.Valid = false;
            result.User.PasswordHash = hashService.GetHash(string.Concat(result.User.Username, hashService.GetHash(user.Password)));
            await dbContext.SaveChangesAsync();

            ViewData["info-message"] = ResetSuccessInfoMessage;
            return View("Login");
        }

        public async Task<IActionResult> Logout()
        {
            await HttpContext.SignOutAsync(CookieAuthenticationDefaults.AuthenticationScheme);
            return Redirect("Login");
        }

        private Task Authenticate(User user)
        {
            var claims = new List<Claim>
            {
                new Claim(ClaimsIdentity.DefaultNameClaimType, user.Username),
                new Claim(ClaimsIdentity.DefaultRoleClaimType, user.Role.ToString()),
            };

            var id = new ClaimsIdentity(claims, "ApplicationCookie", ClaimsIdentity.DefaultNameClaimType,
                ClaimsIdentity.DefaultRoleClaimType);

            return HttpContext.SignInAsync(CookieAuthenticationDefaults.AuthenticationScheme, new ClaimsPrincipal(id));
        }

        private async Task SendVerification(User user)
        {
            var verification = hashService.GetRandom();
            dbContext.UserVerifications.Add(new UserVerification
            {
                UserId = user.Id,
                Verification = verification,
            });
            await dbContext.SaveChangesAsync();
            await sender.SendEmailAsync(user.Username, user.Email,
                $"To verify your email address on CTOX, please follow the link.\nhttps://localhost:5001/Verify/{verification}");
        }
    }
}

using System.Collections.Generic;
using CtoxWebApp.Models;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    public class ErrorController : Controller
    {
        private readonly Dictionary<int, ErrorInfo> Pages = new Dictionary<int, ErrorInfo>()
        {
            { 401, new ErrorInfo { Code = 401, Title = "Unauthorized.", Description = "Seems like you're trying to access something, that's not set up for anons. Authenticate and try again!", RedirectLink = "/Home/Index" } },
            { 404, new ErrorInfo { Code = 404, Title = "Page not found.", Description = "You must have picked the wrong path, beacause I cant find anything useful!", RedirectLink = "/" } }
        };

        [HttpGet("error")]
        public IActionResult Error(int? code)
        {
            if (code != null)
            {
                HttpContext.Response.StatusCode = code.Value;
            }

            if (!Pages.ContainsKey(code.Value))
            {
                return new EmptyResult();
            }

            return View(Pages[code.Value]);
        }
    }
}

﻿using System.Data.Entity;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using CtoxWebApp.DAL;
using CtoxWebApp.Extensions;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Models.ApiModel.View;
using CtoxWebApp.Models.UserModel.Domain;
using CtoxWebApp.Services.Implementations;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    [Authorize]
    public class HomeController : Controller
    {
        private const int HistoryMaxAmount = 10;
        private readonly AppDbContext context;

        public HomeController(AppDbContext context)
        {
            this.context = context;
        }

        public IActionResult Index()
        {
            return View("Convert");
        }

        [HttpPost]
        public async Task<IActionResult> Index(ParseRequestUi request, [FromServices] ApiController apiController)
        {
            if (request is null
                || string.IsNullOrWhiteSpace(request.Data))
            {
                return BadRequest("Empty");
            }

            var api = context.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.User.Username.Equals(User.Identity.Name));

            if (api is null)
            {
                return Unauthorized("No api key");
            }

            var result = await apiController.Parse(
                request.Type == ParseType.Json,
                new ParseRequest
                {
                    Data = request.Data
                }, api.Key);

            return result;
        }

        public IActionResult History()
        {
            var api = context.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.User.Username.Equals(User.Identity.Name));

            if (api is null)
            {
                return View(new ConversionUi
                {
                    HasKey = false,
                    Amount = 0,
                    Conversions = Enumerable.Empty<Conversion>()
                });
            }

            var conversions = context.Conversions
                .Where(c => c.UserId == api.UserId)
                .OrderByDescending(c => c.Time)
                .Take(HistoryMaxAmount)
                .ToList();

            return View(new ConversionUi
            {
                HasKey = true,
                Key = api.Key,
                Amount = conversions.Count,
                Conversions = conversions
            });
        }

        public IActionResult Subscription([FromServices] RestrictionService restriction)
        {
            ViewData["regular-timeout"] = restriction.RegularTimeout;
            ViewData["super-timeout"] = restriction.SuperTimeout;
            ViewData["regular-size"] = restriction.RegularSize;
            ViewData["super-size"] = restriction.SuperSize;
            return View();
        }

        public async Task<IActionResult> Unsubscribe()
        {
            var user = context.Users.First(u => u.Username.Equals(User.Identity.Name));
            if (user.Role != Role.Admin)
            {
                user.Role = Role.Regular;
                var id = User;
                ((ClaimsIdentity)User.Identity).UpdateClaim(ClaimsIdentity.DefaultRoleClaimType, Role.Regular.ToString());
                await HttpContext.SignOutAsync();
                await HttpContext.SignInAsync(CookieAuthenticationDefaults.AuthenticationScheme, id);
                await context.SaveChangesAsync();
            }

            return RedirectToAction("Subscription");
        }

        public async Task<IActionResult> Upgrade()
        {
            var user = context.Users.First(u => u.Username.Equals(User.Identity.Name));
            if (user.Role == Role.Regular)
            {
                user.Role = Role.Super;
                var id = User;
                ((ClaimsIdentity)User.Identity).UpdateClaim(ClaimsIdentity.DefaultRoleClaimType, Role.Super.ToString());
                await HttpContext.SignOutAsync();
                await HttpContext.SignInAsync(CookieAuthenticationDefaults.AuthenticationScheme, id);
                await context.SaveChangesAsync();
            }

            return RedirectToAction("Subscription");
        }

        public IActionResult Api()
        {
            var api = context.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.User.Username.Equals(User.Identity.Name));

            ViewData["api-key"] = api is null ? string.Empty : api.Key;
            return View();
        }
    }
}

﻿using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Models.UserModel.Domain;
using Microsoft.EntityFrameworkCore;

namespace CtoxWebApp.DAL
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options)
            : base(options)
        {
        }

        public DbSet<User> Users { get; set; }
        public DbSet<UserVerification> UserVerifications { get; set; }
        public DbSet<PasswordRestore> PasswordRestores { get; set; }
        public DbSet<Api> Apis { get; set; }
        public DbSet<Conversion> Conversions { get; set; }
    }
}


using System;
using System.Linq;
using System.Security.Claims;

namespace CtoxWebApp.Extensions
{
    public static class ClaimsIdentityExtensions
    {
        public static void UpdateClaim(this ClaimsIdentity identity, string type, string value)
        {
            var claim = identity.Claims.FirstOrDefault(c => c.Type.Equals(type));
            if (claim is null)
            {
                throw new InvalidOperationException("Identity doesnt have specified type");
            }
            
            identity.RemoveClaim(claim);
            identity.AddClaim(new Claim(type, value));
        }
    }
}

using System;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.AspNetCore.Mvc.TagHelpers;
using Microsoft.AspNetCore.Mvc.ViewFeatures;
using Microsoft.AspNetCore.Razor.TagHelpers;

namespace CtoxWebApp.Helpers.Tag
{
    [HtmlTargetElement("a", Attributes = "active-title")]
    [HtmlTargetElement("a", Attributes = "active-class")]
    public class RouterTagHelper : TagHelper
    {
        [ViewContext]
        [HtmlAttributeNotBound]
        public ViewContext ViewContext { get; set; }
        
        [HtmlAttributeName("active-title")]
        public string Title { get; set; }
        
        [HtmlAttributeName("active-class")]
        public string Active { get; set; }

        public override Task ProcessAsync(TagHelperContext context, TagHelperOutput output)
        {
            if (Title is null && !ViewContext.ViewData.ContainsKey("title"))
            {
                throw new ArgumentException("View data should contain title value if no title present");
            }

            var content = output.GetChildContentAsync().Result.GetContent();
            bool condition = Title?.Equals(content) ?? ViewContext.ViewData["title"].Equals(content);

            if (condition)
            {
                var tagBuilder = new TagBuilder("a");
                tagBuilder.AddCssClass(Active ?? "active");
                output.MergeAttributes(tagBuilder);
            }

            return base.ProcessAsync(context, output);
        }
    }
}

using System;
using CtoxWebApp.Models.UserModel.Domain;

namespace CtoxWebApp.Models.ApiModel.Domain
{
    public class Api 
    {
        public int Id { get; set; }
        public string Key { get; set; }
        public DateTime LastUsed { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
    }
}

using System;
using CtoxWebApp.Models.UserModel.Domain;

namespace CtoxWebApp.Models.ApiModel.Domain
{
    public class Conversion
    {
        public int Id { get; set; }
        public DateTime Time { get; set; }
        public ParseType Type { get; set; }
        public string Initial { get; set; }
        public string Result { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
    }
}

﻿namespace CtoxWebApp.Models.ApiModel.Domain
{
    public class ParseRequest
    {
        public string Data { get; set; }
    }
}

namespace CtoxWebApp.Models.ApiModel.Domain
{
    public enum ParseType
    {
        Xml,
        Json
    }
}

using System.Collections.Generic;
using CtoxWebApp.Models.ApiModel.Domain;

namespace CtoxWebApp.Models.ApiModel.View
{
    public class ConversionUi
    {
        public bool HasKey { get; set; }
        public string Key { get; set; }
        public int Amount { get; set; }
        public IEnumerable<Conversion> Conversions { get; set; }
    }
}

using CtoxWebApp.Models.ApiModel.Domain;

namespace CtoxWebApp.Models.ApiModel.View
{
    public class ParseRequestUi
    {
        public string Data { get; set; }
        public ParseType Type { get; set; }
    }
}

namespace CtoxWebApp.Models
{
    public class ErrorInfo
    {
        public int Code { get; set; }
        public string Title { get; set; }
        public string Description { get; set; }
        public string RedirectLink { get; set; }
    }
}

﻿namespace CtoxWebApp.Models.UserModel.Domain
{
    public class PasswordRestore
    {
        public int Id { get; set; }
        public string Restore { get; set; }
        public bool Valid { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
    }
}

﻿namespace CtoxWebApp.Models.UserModel.Domain
{
    public enum Role 
    {
        Regular,
        Super,
        Admin,
    }
    public class User
    {
        public int Id { get; set; }
        public string Username { get; set; }
        public string Email { get; set; }
        public string PasswordHash { get; set; }
        public bool Confirmed { get; set; }
        public Role Role { get; set; }
    }
}

﻿namespace CtoxWebApp.Models.UserModel.Domain
{
    public class UserVerification
    {
        public int Id { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
        public string Verification { get; set; }
    }
}

﻿using System.ComponentModel.DataAnnotations;

namespace CtoxWebApp.Models.UserModel.View
{
    public class UserLogin
    {
        public string Username { get; set; }
        
        [DataType(DataType.Password)]
        public string Password { get; set; }
    }
}

﻿using System.ComponentModel.DataAnnotations;
using CtoxWebApp.Attributes.Validations;

namespace CtoxWebApp.Models.UserModel.View
{
    public class UserRegister
    {
        [Required(ErrorMessage = "Username should be filled")]
        [StringLength(60, MinimumLength = 3, ErrorMessage = "Username length should be between 3 and 60")]
        [RegularExpression("[a-zA-Z]+", ErrorMessage = "Username should consist only of letters")]
        [UniqueUsername(ErrorMessage = "Username is taken")]
        public string Username { get; set; }
        
        [Required(ErrorMessage = "Email should be filled")]
        [DataType(DataType.EmailAddress)]
        [Email(ErrorMessage = "Email address is not valid")]
        [UniqueEmail(ErrorMessage = "Email is taken")]
        public string Email { get; set; }
        
        [Required(ErrorMessage = "Password should be filled")]
        [DataType(DataType.Password)]
        [StringLength(500, MinimumLength = 6, ErrorMessage = "Password should be at least 6 length")]
        [StrongPassword(PasswordHas.Digit | PasswordHas.Lowercase | PasswordHas.Uppercase, ErrorMessage = "Password should contain a digit, lowercase and uppercase letter")]
        public string Password { get; set; }
    }
}

﻿using System.ComponentModel.DataAnnotations;
using CtoxWebApp.Attributes.Validations;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Models.UserModel.View
{
    public class UserRestore
    {
        [Required(ErrorMessage = "Password should be filled")]
        [DataType(DataType.Password)]
        [StringLength(500, MinimumLength = 6, ErrorMessage = "Password should be at least 6 length")]
        [StrongPassword(PasswordHas.Digit | PasswordHas.Lowercase | PasswordHas.Uppercase, ErrorMessage = "Password should contain a digit, lowercase and uppercase letter")]
        public string Password { get; set; }
        
        [Display(Name = "Repeat password")]
        [DataType(DataType.Password)]
        [Compare("Password", ErrorMessage = "Passwords are not equal")]
        public string RepeatPassword { get; set; }
        
        [HiddenInput(DisplayValue = false)]
        public string Restore { get; set; }
    }
}

﻿namespace CtoxWebApp.Models.UserModel.View
{
    public class UserRestoreRequest
    {
        public string Email { get; set; }
    }
}

using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Hosting;

namespace CtoxWebApp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            CreateHostBuilder(args).Build().Run();
        }

        public static IHostBuilder CreateHostBuilder(string[] args) =>
            Host.CreateDefaultBuilder(args)
                .ConfigureWebHostDefaults(webBuilder =>
                {
                    webBuilder.UseStartup<Startup>();
                });
    }
}


﻿using System.Text;
using System.Threading.Tasks;
using CtoxWebApp.Services.Interfaces;
using MailKit.Net.Smtp;
using Microsoft.Extensions.Configuration;
using MimeKit;

namespace CtoxWebApp.Services.Implementations
{
    public class EmailSenderService: IEmailSenderService
    {
        private readonly string email;
        private readonly string password;

        public EmailSenderService(IConfiguration configuration)
        {
            email = configuration["Email:Name"];
            password = configuration["Email:Password"];
        }

        public async Task SendEmailAsync(string receiverName, string receiverEmail, string body)
        {

            var message = new MimeMessage();
            var from = new MailboxAddress(Encoding.UTF8, "Ctox", email);
            var to = new MailboxAddress(Encoding.UTF8, receiverName, receiverEmail);
            message.From.Add(from);
            message.To.Add(to);
            message.Subject = "Ctox Service Notification.";

            var bodyBuilder = new BodyBuilder
            {
                TextBody = body,
            };
            message.Body = bodyBuilder.ToMessageBody();

            var smtp = new SmtpClient();
            await smtp.ConnectAsync("smtp.gmail.com", 465, true);

            await smtp.AuthenticateAsync(Encoding.UTF8, email, password);

            await smtp.SendAsync(message);
            await smtp.DisconnectAsync(true);
            smtp.Dispose();
        }
    }
}

using System;
using System.IO;
using System.IO.Compression;
using System.Text;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations
{
    public class GzipCompressService: IStringCompressService
    {
        public string Compress(string content)
        {
            string result;
            using (var so = new MemoryStream())
            {
                using (var gzip = new GZipStream(so, CompressionMode.Compress))
                {
                    using (var si = new MemoryStream(Encoding.UTF8.GetBytes(content)))
                    {
                        si.CopyTo(gzip);
                    }
                }

                result = Convert.ToBase64String(so.ToArray());
            }

            return result;
        }

        public string Decompress(string content)
        {
            string result;
            using (var si = new MemoryStream(Convert.FromBase64String(content)))
            {
                using (var gzip = new GZipStream(si, CompressionMode.Decompress))
                {
                    using (var so = new MemoryStream())
                    {
                        gzip.CopyTo(so);
                        result = Encoding.UTF8.GetString(so.ToArray());
                    }
                }
            }

            return result;
        }
    }
}

﻿using System;
using System.Security.Cryptography;
using System.Text;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations
{
    public class HashService: IHashService
    {
        public string GetHash(string content)
        {
            var data = Encoding.UTF8.GetBytes(content);
            return GetHash(data);
        }

        public string GetHashSafe(string content)
        {
            var data = Encoding.UTF8.GetBytes(content);
            return GetHashSafe(data);
        }

        public string GetHash(byte[] data)
        {
            var sha = new SHA256CryptoServiceProvider();
            var enc = sha.ComputeHash(data);
            return Convert.ToBase64String(enc);
        }

        public string GetHashSafe(byte[] data)
        {
            var sha = new SHA256CryptoServiceProvider();
            var enc = sha.ComputeHash(data);
            return Convert.ToBase64String(enc).TrimEnd('=').Replace('+', '-').Replace('/', '_');
        }

        public string GetRandom()
        {
            var data = new byte[8];
            var rnd = new Random();
            rnd.NextBytes(data);
            return GetHashSafe(data);
        }
    }
}

using System;
using System.Text;
using System.Threading.Tasks;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations.Mocks
{
    public class ParseAsyncMock : IParseAsyncService
    {
        private readonly IHashService hash;

        public ParseAsyncMock(IHashService hash)
        {
            this.hash = hash;
        }

        public Task<string> ParseAsync(string content)
        {
            return Task.Run(() => {
                var resultBuilder = new StringBuilder();

                for (int i = 0; i < new Random().Next(10, 20); i++)
                {
                    resultBuilder.Append($"<text>{hash.GetRandom()}</text>");
                }

                return $"<parse>{resultBuilder}</parse>";
            });
        }
    }
}

using System.Threading.Tasks;
using CtoxService;
using CtoxWebApp.Services.Interfaces;
using Microsoft.Extensions.Configuration;

namespace CtoxWebApp.Services.Implementations
{
    public class ParseAsyncService : IParseAsyncService
    {
        private readonly Ctox parse;
        
        public ParseAsyncService(IConfiguration configuration)
        {
            parse = new Ctox(configuration["ParseCommand"]);
        }

        public Task<string> ParseAsync(string content)
        {
            return parse.ParseAsync(content);
        }
    }
}

﻿using System;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Models.UserModel.Domain;
using Microsoft.Extensions.Configuration;

namespace CtoxWebApp.Services.Implementations
{
    public class RestrictionService
    {
        private readonly TimeSpan[] timeouts;
        private readonly int[] maxSizes;
        
        public RestrictionService(IConfiguration configuration)
        {
            var names = Enum.GetNames(typeof(Role));
            timeouts = new TimeSpan[names.Length];
            maxSizes = new int[names.Length];

            for (int i = 0; i < names.Length; i++)
            {
                timeouts[i] = TimeSpan.FromMinutes(Convert.ToDouble(configuration[$"Restrictions:Timeouts:{names[i]}"]));
                maxSizes[i] = Convert.ToInt32(configuration[$"Restrictions:Sizes:{names[i]}"]);
            }
        }

        public int RegularTimeout => timeouts[(int) Role.Regular].Minutes;
        public int SuperTimeout => timeouts[(int) Role.Super].Minutes;
        public int RegularSize => maxSizes[(int) Role.Regular];
        public int SuperSize => maxSizes[(int) Role.Super];

        public bool IsAllowedTimeout(Api api)
        {
            var diff = DateTime.Now - api.LastUsed;
            return diff > timeouts[(int) api.User.Role];
        }

        public bool IsAllowedSize(Api api, int size)
        {
            return size <= maxSizes[(int) api.User.Role];
        }
    }
}

using System.Threading.Tasks;

namespace CtoxWebApp.Services.Interfaces
{
    public interface IEmailSenderService
    {
        Task SendEmailAsync(string receiverName, string receiverEmail, string body);
    }
}

namespace CtoxWebApp.Services.Interfaces
{
    public interface IHashService
    {
        public string GetHash(string content);
        public string GetHash(byte[] data);
        public string GetHashSafe(string content);
        public string GetHashSafe(byte[] data);
        public string GetRandom();
    }
}

using System.Threading.Tasks;

namespace CtoxWebApp.Services.Interfaces
{
    public interface IParseAsyncService
    {
        Task<string> ParseAsync(string content);
    }
}

namespace CtoxWebApp.Services.Interfaces
{
    public interface IStringCompressService
    {
        string Compress(string content);
        string Decompress(string content);
    }
}

using System.Threading.Tasks;
using CtoxWebApp.Attributes.Filters;
using CtoxWebApp.DAL;
using CtoxWebApp.Services.Implementations;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.DataProtection;
using Microsoft.AspNetCore.DataProtection.AuthenticatedEncryption.ConfigurationModel;
using Microsoft.AspNetCore.DataProtection.AuthenticatedEncryption;

namespace CtoxWebApp
{
    public class Startup
    {
        public Startup(IConfiguration configuration)
        {
            var builder = new ConfigurationBuilder()
                .AddConfiguration(configuration)
                .AddJsonFile("devsettings.json", true)
                .AddEnvironmentVariables();

            Configuration = builder.Build();
        }

        private IConfiguration Configuration { get; }

        // This method gets called by the runtime. Use this method to add services to the container.
        public void ConfigureServices(IServiceCollection services)
        {
            services
                .AddDataProtection()
                .UseCryptographicAlgorithms(new AuthenticatedEncryptorConfiguration() 
                {
                    EncryptionAlgorithm = EncryptionAlgorithm.AES_256_CBC,
                    ValidationAlgorithm = ValidationAlgorithm.HMACSHA256
                });

            services.AddResponseCompression(o => o.EnableForHttps = true);

            services.AddTransient(p => Configuration);
            services.AddTransient<IHashService, HashService>();
            services.AddTransient<IStringCompressService, GzipCompressService>();
            services.AddTransient<ApiKey>();
            services.AddSingleton<IParseAsyncService, ParseAsyncService>();
            services.AddSingleton<IEmailSenderService, EmailSenderService>();
            services.AddSingleton<RestrictionService>();

            services
                .AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
                .AddCookie(o =>
                {
                    o.LoginPath = new PathString("/Auth/Login");
                    o.Events.OnRedirectToAccessDenied = context =>
                    {
                        context.Response.StatusCode = 404;
                        return Task.CompletedTask;
                    };
                });

            services
                .AddControllersWithViews()
                .AddControllersAsServices()
                .AddRazorRuntimeCompilation();

            var appContextConnection = Configuration.GetConnectionString("AppContext");
            services.AddDbContext<AppDbContext>(options =>
                options
                    .UseLazyLoadingProxies()
                    .UseMySql(appContextConnection, ServerVersion.AutoDetect(appContextConnection)));
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            app.EnsureConnected<AppDbContext>();
            app.EnsureMigrated<AppDbContext>();

            app.UseResponseCompression();

            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }

            app.UseStatusCodePagesWithReExecute("/error", "?code={0}");

            app.UseDefaultFiles();

            app.UseStaticFiles();

            app.UseRouting();

            app.UseAuthentication();
            app.UseAuthorization();

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllerRoute(
                    "verification",
                    "Verify/{verificationString:required}",
                    new { controller = "Auth", action = "Verify" });
                endpoints.MapControllerRoute(
                    "restorepassword",
                    "Reset/{resetString:required}",
                    new { controller = "Auth", action = "Reset" });
                endpoints.MapControllerRoute(
                    name: "default",
                    pattern: "{controller}/{action}"
                );
                endpoints.MapControllers();
            });
        }
    }
}


