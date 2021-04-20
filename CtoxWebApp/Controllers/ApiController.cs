using System;
using System.Data.Entity;
using System.Linq;
using System.Threading.Tasks;
using System.Xml.Linq;
using CtoxWebApp.Attributes.Filters;
using CtoxWebApp.DAL;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Services.Implementations;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;

namespace CtoxWebApp.Controllers
{
    [ServiceFilter(typeof(ApiKey))]
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
        private readonly IParseService parse;
        private readonly IStringCompressService compress;

        public ApiController(AppDbContext context, RestrictionService restriction, IParseService parse, IStringCompressService compress)
        {
            this.context = context;
            this.restriction = restriction;
            this.parse = parse;
            this.compress = compress;
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
        public async Task<IActionResult> Create([FromServices]IHashService hash)
        {
            var user = context.Users.First(u => u.Username.Equals(HttpContext.User.Identity.Name));
            var api = context.Apis.FirstOrDefault(a => a.UserId == user.Id);

            if (api is null)
            {
                api = new Api
                {
                    Key = hash.GetRandom(),
                    LastUsed = DateTime.MinValue,
                    UserId = user.Id
                };
                
                context.Apis.Add(api);
            }
            else
            {
                api.Key = hash.GetRandom();
            }

            await context.SaveChangesAsync();
            return StatusCode(201, new { api.Key });
        }

        [HttpPost("parse")]
        public async Task<IActionResult> Parse(
            bool? json, 
            [FromBody] ParseRequest request, 
            [FromHeader(Name = "x-api-key")] string key)
        {
            if (request is null 
                || string.IsNullOrWhiteSpace(request.Data))
            {
                return BadRequest("Empty");
            }

            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));

            if (!restriction.IsAllowedTimeout(api))
            {
                return StatusCode(429, "Timeout");
            }

            if (!restriction.IsAllowedSize(api, request.Data.Length))
            {
                return StatusCode(405, "Size");
            }
            
            api.LastUsed = DateTime.Now;

            var parseResult = parse.Parse(request.Data);
            context.Conversions.Add(new Conversion
            {
                Initial = compress.Compress(request.Data),
                Result = compress.Compress(parseResult),
                Time = api.LastUsed,
                UserId = api.UserId,
            });
            await context.SaveChangesAsync();
            
            if (json != true)
            {
                return Content(parseResult, "application/xml");
            }

            return Content(JsonConvert.SerializeXNode(XElement.Parse(parseResult)), "application/json");
        }

        [HttpGet("history")]
        public IActionResult History(int? skip, int? limit, [FromHeader(Name = "x-api-key")] string key)
        {
            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));
            
            var conversions = context.Conversions
                .Where(c => c.UserId == api.UserId)
                .Skip(skip ?? 0)
                .Take(limit ?? 100)
                .Select(c => new { c.Id, c.Time });

            var result = new { Amount = conversions.Count(), Data = conversions };
            return Content(JsonConvert.SerializeObject(result), "application/json");
        }

        [HttpGet("view")]
        public IActionResult View(int? id, [FromHeader(Name = "x-api-key")] string key)
        {
            if (id is null)
            {
                return BadRequest();
            }
            
            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));

            var conversion = context.Conversions.FirstOrDefault(c => c.Id == id);

            if (conversion is null)
            {
                return NotFound();
            }

            if (conversion.UserId != api.UserId)
            {
                return StatusCode(403);
            }

            var result = new
            {
                Initial = compress.Decompress(conversion.Initial),
                Result = compress.Decompress(conversion.Result)
            };

            return Content(JsonConvert.SerializeObject(result), "application/json");
        }
    }
}