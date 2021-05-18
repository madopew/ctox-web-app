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