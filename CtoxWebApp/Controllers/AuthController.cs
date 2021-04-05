using System.Linq;
using CtoxWebApp.DAL;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    public class AuthController : Controller
    {
        private AppContext context;
        
        public AuthController(AppContext context)
        {
            this.context = context;
        }

        // GET
        public IActionResult Index()
        {
            return View(context.Users.First());
        }
    }
}