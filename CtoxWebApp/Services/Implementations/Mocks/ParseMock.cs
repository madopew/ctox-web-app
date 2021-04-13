using System.Linq;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations.Mocks
{
    public class ParseMock : IParseService
    {
        private readonly IHashService hash;
        
        public ParseMock(IHashService hash)
        {
            this.hash = hash;
        }

        public string Parse(string content)
        {
            var randomness = string.Concat(Enumerable.Repeat(hash.GetRandom(), 10));
            return $"<text>{randomness}</text>";
        }
    }
}