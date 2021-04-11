using System;
using System.Data.Entity;
using System.Linq;
using System.Text.Json.Serialization;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using Castle.Core.Configuration;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Services;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using IConfiguration = Microsoft.Extensions.Configuration.IConfiguration;

namespace CtoxWebApp.Controllers
{
    [Route("api")]
    public class ApiController : ControllerBase
    {
        private const string TestResultText = "<function>" +
                                              "<prototype> void test ( ) </prototype>" +
                                              "<body>" +
                                              "<expression hascalls = \"true\">" +
                                              "<funccall>" +
                                              "<name> printf </name>" +
                                              "<arguments>\"%s\\n\" , \"Hello from api!\" </arguments>" +
                                              "</funccall>" +
                                              "<text> printf ( \"%s\\n\" , \"Hello from api!\" ) </text>" +
                                              "</expression>" +
                                              "</body>" +
                                              "</function>";
        
        private static readonly string TestResultJson = JsonConvert.SerializeXNode(XElement.Parse(TestResultText));

        private readonly AppDbContext context;
        private readonly RestrictionService restriction;
        
        public ApiController(AppDbContext context, RestrictionService restriction)
        {
            this.context = context;
            this.restriction = restriction;
        }

        [HttpGet("test")]
        public IActionResult Test(bool? json)
        {
            if (json != true)
            {
                return Content(TestResultText, "application/xml");
            }

            return Content(TestResultJson, "application/json");
        }

        [Authorize]
        [HttpGet("create")]
        public async Task<IActionResult> Create([FromServices]HashService hash)
        {
            var user = context.Users.First(u => u.Username.Equals(User.Identity.Name));
            var api = context.Apis.FirstOrDefault(a => a.UserId == user.Id);

            if (api is null)
            {
                context.Apis.Add(new Api
                {
                    Key = hash.GetRandom(),    
                    LastUsed = DateTime.MinValue,
                    UserId = user.Id
                });
            }
            else
            {
                api.Key = hash.GetRandom();
            }

            await context.SaveChangesAsync();
            return Ok();
        }

        [HttpPost("parse")]
        public async Task<IActionResult> Parse([FromQuery]bool? json, [FromBody]ParseRequest request)
        {
            if (request is null)
            {
                return BadRequest();
            }

            var api = context.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.Key.Equals(request.Key));

            if (api is null)
            {
                return Unauthorized();
            }

            if (!restriction.IsAllowedTimeout(api))
            {
                return StatusCode(429, "Timeout");
            }

            if (!restriction.IsAllowedSize(api, request.Data.Length))
            {
                return StatusCode(405, "Size");
            }
            
            api.LastUsed = DateTime.Now;
            await context.SaveChangesAsync();
            
            //TODO add to history gzip
            //TODO actual parsing

            if (json != true)
            {
                return Content(TestResultText, "application/xml");
            }

            return Content(TestResultJson, "application/json");
        }
    }
}