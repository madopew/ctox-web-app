using CtoxWebApp.Models.ApiModel.View;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    [Authorize]
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View("Convert");
        }

        public IActionResult History()
        {
            return View();
        }
        
        public IActionResult Balance()
        {
            return View();
        }
        
        public IActionResult Api()
        {
            return View();
        }
        
        public IActionResult Manage()
        {
            return View();
        }
    }
}