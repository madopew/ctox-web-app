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

        private const string ContentTypeJson = "application/json";
        private const string ContentTypeXml = "application/xml";
        private const string ApiKeyHeader = "x-api-key";

        private static readonly string TestResultJson = JsonConvert.SerializeXNode(XElement.Parse(TestResultText));

        private readonly AppDbContext context;
        private readonly RestrictionService restriction;
        private readonly IParseService parse;
        private readonly IStringCompressService compress;

        public ApiController(AppDbContext context, RestrictionService restriction, IParseService parse,
            IStringCompressService compress)
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
                return Content(TestResultText, ContentTypeXml);
            }

            return Content(TestResultJson, ContentTypeJson);
        }

        [Authorize]
        [AllowNoApi]
        [HttpGet("create")]
        public async Task<IActionResult> Create([FromServices] IHashService hash)
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
            return StatusCode(201, new {api.Key});
        }

        [HttpPost("parse")]
        public async Task<IActionResult> Parse(
            bool? json,
            [FromBody] ParseRequest request,
            [FromHeader(Name = ApiKeyHeader)] string key)
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
            if (json == true)
            {
                parseResult = JsonConvert.SerializeXNode(XElement.Parse(parseResult));
            }

            context.Conversions.Add(new Conversion
            {
                Initial = compress.Compress(request.Data),
                Result = compress.Compress(parseResult),
                Type = json == true ? ParseType.Json : ParseType.Xml,
                Time = api.LastUsed,
                UserId = api.UserId,
            });
            await context.SaveChangesAsync();

            return Content(parseResult, json == true ? ContentTypeJson : ContentTypeXml);
        }

        [HttpGet("history")]
        public IActionResult History(
            DateTime? day,
            bool? ascending,
            int? skip,
            int? limit,
            [FromHeader(Name = ApiKeyHeader)] string key)
        {
            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));

            var conversions = context.Conversions
                .Where(c => c.UserId == api.UserId);

            conversions = SearchConversions(conversions, day, ascending, skip, limit);

            var data = conversions.Select(c => new
            {
                c.Id,
                c.Time,
                c.Type
            });

            var result = new {Amount = data.Count(), Data = data};
            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }

        [HttpGet("view")]
        public IActionResult View(int? id, [FromHeader(Name = ApiKeyHeader)] string key)
        {
            if (id is null)
            {
                return BadRequest();
            }

            var api = context.Apis
                .Include(a => a.User)
                .First(a => a.Key.Equals(key));

            var conversion = context.Conversions.FirstOrDefault(c => c.Id == id);

            if (conversion is null || conversion.UserId != api.UserId)
            {
                return NotFound();
            }

            var result = new
            {
                Initial = compress.Decompress(conversion.Initial),
                Result = compress.Decompress(conversion.Result)
            };

            return Content(JsonConvert.SerializeObject(result), ContentTypeJson);
        }

        private IQueryable<Conversion> SearchConversions(
            IQueryable<Conversion> conversions,
            DateTime? day,
            bool? ascending,
            int? skip,
            int? limit)
        {
            if (day != null)
            {
                conversions = conversions.Where(c => c.Time.Date == ((DateTime) day).Date);
            }

            conversions = ascending == false ? 
                conversions.OrderByDescending(c => c.Time) : 
                conversions.OrderBy(c => c.Time);

            if (skip != null)
            {
                conversions = conversions.Skip((int) skip);
            }

            if (limit != null)
            {
                conversions = conversions.Take((int) limit);
            }

            return conversions;
        }
    }
}