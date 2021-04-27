using System.Threading.Tasks;
using CtoxService;
using CtoxWebApp.Services.Interfaces;
using Microsoft.Extensions.Configuration;

namespace CtoxWebApp.Services.Implementations
{
    public class ParseAsyncService : IParseAsyncService
    {
        private readonly Ctox parse;
        
        public ParseAsyncService(IConfiguration configuration)
        {
            parse = new Ctox(configuration["ParseCommand"]);
        }

        public Task<string> ParseAsync(string content)
        {
            return parse.ParseAsync(content);
        }
    }
}