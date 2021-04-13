using System.Linq;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations.Mocks
{
    public class ParseMock : IParseService
    {
        private readonly HashService hash;
        
        public ParseMock(HashService hash)
        {
            this.hash = hash;
        }

        public string Parse(string content)
        {
            return string.Concat(Enumerable.Repeat(hash.GetRandom(), 10));
        }
    }
}