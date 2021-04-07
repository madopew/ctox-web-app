using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using CtoxWebApp.DAL;
using CtoxWebApp.Models;
using CtoxWebApp.Services;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    public class AuthController : Controller
    {
        private readonly AppDbContext dbContext;
        private readonly HashService hashService;
        
        public AuthController(AppDbContext dbContext, HashService hashService)
        {
            this.dbContext = dbContext;
            this.hashService = hashService;
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
                    "Both username and password should be filled in. Please check your username and password and try again.";
                return View();
            }

            var hash = hashService.GetHash(string.Concat(user.Username, hashService.GetHash(user.Password)));
            
            var result = dbContext.Users
                .FirstOrDefault(u => u.Username.Equals(user.Username, StringComparison.Ordinal) &&
                                     u.PasswordHash.Equals(hash, StringComparison.Ordinal));

            if (result is null)
            {
                ViewData["error-message"] =
                    "We couldn't find an account matching the username and password you entered. Please check your username and password and try again.";
                return View();
            }

            if (!result.Confirmed)
            {
                ViewData["error-message"] =
                    "It seems like you didn't confirm your email address. Please make sure that you followed the link sent to your email.";
                return View();
            }

            var role = dbContext.Roles.First(r => r.Id == result.RoleId);
            result.Role = role;

            await Authenticate(result);
            return RedirectToAction("Index", "Home");
        }
        
        public IActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Register(UserRegister user)
        {
            if (ModelState.IsValid)
            {
                var role = dbContext.Roles.First(r => r.Name == "User");
                var registered = new User
                {
                    Username = user.Username,
                    Email = user.Email,
                    PasswordHash =
                        hashService.GetHash(string.Concat(user.Username, hashService.GetHash(user.Password))),
                    Confirmed = false,
                    Role = role,
                };

                dbContext.Users.Add(registered);
                dbContext.SaveChanges();
                return Redirect("Login");
            }
            
            return View(user);
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
                new Claim(ClaimsIdentity.DefaultRoleClaimType, user.Role.Name),
            };

            var id = new ClaimsIdentity(claims, "ApplicationCookie", ClaimsIdentity.DefaultNameClaimType,
                ClaimsIdentity.DefaultRoleClaimType);

            return HttpContext.SignInAsync(CookieAuthenticationDefaults.AuthenticationScheme, new ClaimsPrincipal(id));
        }
    }
}