using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return Content("Hello world!");
        }
    }
}