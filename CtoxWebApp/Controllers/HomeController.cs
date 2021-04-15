using System;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Models.ApiModel.View;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Controllers
{
    [Authorize]
    public class HomeController : Controller
    {
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
        public async Task<IActionResult> Index(ParseRequestUi request, [FromServices] ApiController apiController, [FromServices] IHashService hash)
        {
            if (request is null
                || string.IsNullOrWhiteSpace(request.Data))
            {
                return BadRequest();
            }

            var user = context.Users
                .First(u => u.Username.Equals(HttpContext.User.Identity.Name));
            var api = context.Apis
                .FirstOrDefault(a => a.UserId.Equals(user.Id));

            if (api is null)
            {
                api = new Api
                {
                    Key = hash.GetRandom(),
                    LastUsed = DateTime.MinValue,
                    UserId = user.Id
                };
                
                context.Apis.Add(api);
                await context.SaveChangesAsync();
            }

            var result = await apiController.Parse(request.Type == ParseType.Json, new ParseRequest
            {
                Key = api.Key,
                Data = request.Data
            });
            
            return result;
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