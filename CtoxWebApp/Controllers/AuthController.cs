﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using CtoxWebApp.DAL;
using CtoxWebApp.Models;
using CtoxWebApp.Services;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

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
        public async Task<IActionResult> Register(UserRegister user)
        {
            if (!ModelState.IsValid) return View(user);
            
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
                return NotFound();
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
                    "Invalid verification string. Please make sure you followed the link correctly.";
                return View("Login");
            }

            if (result.User.Confirmed)
            {
                ViewData["error-message"] =
                    "Your email have been already confirmed.";
                return View("Login");
            }

            result.User.Confirmed = true;
            await dbContext.SaveChangesAsync();
            
            ViewData["info-message"] = "Your email has been verified.";
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
                new Claim(ClaimsIdentity.DefaultRoleClaimType, user.Role.Name),
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
        }
    }
}