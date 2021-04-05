using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    public class HomeController : Controller
    {
        // GET
        public IActionResult Index()
        {
            return View();
        }
    }
}