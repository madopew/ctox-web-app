using System;
using System.Linq;
using System.Text;
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
            var resultBuilder = new StringBuilder();

            for (int i = 0; i < new Random().Next(10, 20); i++)
            {
                resultBuilder.Append($"<text>{hash.GetRandom()}</text>");
            }

            return $"<parse>{resultBuilder}</parse>";
        }
    }
}