using System.Data.Entity;
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