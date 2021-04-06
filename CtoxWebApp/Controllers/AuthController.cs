using System;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using CtoxWebApp.Models;
using CtoxWebApp.Services;
using Microsoft.AspNetCore.Mvc;
using AppContext = CtoxWebApp.DAL.AppContext;

namespace CtoxWebApp.Controllers
{
    public class AuthController : Controller
    {
        private readonly AppContext context;
        private readonly HashService hashService;
        
        public AuthController(AppContext context, HashService hashService)
        {
            this.context = context;
            this.hashService = hashService;
        }

        public IActionResult Login()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Login(UserLogin user)
        {
            var hash = hashService.GetHash(string.Concat(user.Username, hashService.GetHash(user.Password)));
            
            var result = context.Users
                .FirstOrDefault(u => u.Username.Equals(user.Username, StringComparison.Ordinal) &&
                                     u.PasswordHash.Equals(hash, StringComparison.Ordinal) &&
                                     u.Confirmed);

            if (result is null)
            {
                ViewData["error-message"] =
                    "We couldn't find an account matching the username and password you entered. Please check your username and password and try again.";
                return View();
            }

            return null;
        }
    }
}