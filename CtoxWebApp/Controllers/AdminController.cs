using System;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.UserModel.Domain;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;

namespace CtoxWebApp.Controllers
{
    [Authorize(Roles = "Admin")]
    [Route("/api/admin")]
    public class AdminController : ControllerBase
    {
        private const string ContentTypeJson = "application/json";
        private readonly AppDbContext context;

        public AdminController(AppDbContext context)
        {
            this.context = context;
        }

        [HttpGet("users")]
        public IActionResult GetUsers()
        {
            var users =
                from u in context.Users
                select new { 
                    u.Id, 
                    u.Username, 
                    u.Email, 
                    u.Confirmed, 
                    Role = u.Role.ToString() 
                    };

            return Content(JsonConvert.SerializeObject(users), ContentTypeJson);            
        }

        [HttpDelete("user")]
        public async Task<IActionResult> DeleteUser(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            context.Users.Remove(user);
            await context.SaveChangesAsync();
            return Ok();
        }

        [HttpGet("stat")]
        public IActionResult GetStat(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            var api = context.Apis.FirstOrDefault(a => a.UserId == id);
            var res = context.PasswordRestores.Where(r => r.UserId == id).Count();

            if (api is null)
            {
                return Content(JsonConvert.SerializeObject(new { HasKey = false, Restores = res }), ContentTypeJson);
            }

            var result = new {
                HasKey = true,
                Key = api.Key,
                LastUsed = api.LastUsed,
                Conversions = context.Conversions.Where(c => c.UserId == id).Count(),
                Restores = res
            };
            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }

        [HttpPut("confirmed")]
        public async Task<IActionResult> SetConfirmed(int? id, bool? confirmed)
        {
            if (id is null || confirmed is null)
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            user.Confirmed = (bool) confirmed;
            await context.SaveChangesAsync();

            return Ok();
        }

        [HttpPut("role")]
        public async Task<IActionResult> SetRole(int? id, Role? role)
        {
            if (id is null || role is null)
            {
                return BadRequest();
            }

            if (!Enum.IsDefined(typeof(Role), role))
            {
                return BadRequest();
            }

            var user = context.Users.FirstOrDefault(u => u.Id == id);
            if (user is null)
            {
                return NotFound();
            }

            user.Role = (Role) role;
            await context.SaveChangesAsync();

            return Ok();
        }

        [HttpGet("conversions")]
        public IActionResult GetConversions(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var conversions = context.Conversions
                .Where(c => c.UserId == id)
                .Select(c => new { c.Id, c.Time, Type = c.Type.ToString()});

            if (conversions.Count() == 0)
            {
                return NotFound();
            }    

            return Content(JsonConvert.SerializeObject(conversions), ContentTypeJson);
        }

        [HttpDelete("conversion")]
        public async Task<IActionResult> DeleteConversion(int? id)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var conversion = context.Conversions.FirstOrDefault(c => c.Id == id);
            if (conversion is null)
            {
                return NotFound();
            }

            context.Conversions.Remove(conversion);
            await context.SaveChangesAsync();
            return Ok();
        }

        [HttpGet("view")]
        public IActionResult ViewConversion(int? id, [FromServices] IStringCompressService compress)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var conversion = context.Conversions.FirstOrDefault(c => c.Id == id);
            if (conversion is null)
            {
                return NotFound();
            }

            var result = new {
                Initial = compress.Decompress(conversion.Initial),
                Result = compress.Decompress(conversion.Result)
            };

            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }
    }
}