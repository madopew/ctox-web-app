﻿using System;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using CtoxWebApp.DAL;
using CtoxWebApp.Models;
using CtoxWebApp.Services;
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
            return View();
        }

        [HttpPost]
        public IActionResult Login(UserLogin user)
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

            // TODO add authentication
            return null;
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
                var registered = new User
                {
                    Username = user.Username,
                    Email = user.Email,
                    PasswordHash =
                        hashService.GetHash(string.Concat(user.Username, hashService.GetHash(user.Password))),
                    Confirmed = false,
                    RoleId = 1,
                };

                dbContext.Users.Add(registered);
                dbContext.SaveChanges();
                return Redirect("Login");
            }
            
            return View(user);
        }
    }
}