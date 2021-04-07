using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    [Authorize]
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return Content("Hello world!");
        }

        [Authorize(Roles = "Super, Admin")]
        public IActionResult About()
        {
            return Content("No user");
        }
    }
}