using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Models.ApiModel.View;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    [Authorize]
    public class HomeController : Controller
    {
        private const int HistoryMaxAmount = 10;
        private readonly AppDbContext context;

        public HomeController(AppDbContext context)
        {
            this.context = context;
        }

        public IActionResult Index()
        {
            return View("Convert");
        }

        [HttpPost]
        public async Task<IActionResult> Index(ParseRequestUi request, [FromServices] ApiController apiController)
        {
            if (request is null
                || string.IsNullOrWhiteSpace(request.Data))
            {
                return BadRequest();
            }

            var api = context.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.User.Username.Equals(User.Identity.Name));

            if (api is null)
            {
                return Unauthorized();
            }

            var result = await apiController.Parse(
                request.Type == ParseType.Json,
                new ParseRequest
                {
                    Data = request.Data
                }, api.Key);

            return result;
        }

        public IActionResult History()
        {
            var api = context.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.User.Username.Equals(User.Identity.Name));

            if (api is null)
            {
                return View(new ConversionUi
                {
                    HasKey = false,
                    Amount = 0,
                    Conversions = Enumerable.Empty<Conversion>()
                });
            }

            var conversions = context.Conversions
                .Where(c => c.UserId == api.UserId)
                .Take(HistoryMaxAmount)
                .ToList();

            return View(new ConversionUi
            {
                HasKey = true,
                Key = api.Key,
                Amount = conversions.Count,
                Conversions = conversions
            });
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