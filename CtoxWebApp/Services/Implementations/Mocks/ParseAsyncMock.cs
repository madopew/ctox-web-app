using System;
using System.Text;
using System.Threading.Tasks;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations.Mocks
{
    public class ParseAsyncMock : IParseAsyncService
    {
        private readonly IHashService hash;

        public ParseAsyncMock(IHashService hash)
        {
            this.hash = hash;
        }

        public Task<string> ParseAsync(string content)
        {
            return Task.Run(() => {
                var resultBuilder = new StringBuilder();

                for (int i = 0; i < new Random().Next(10, 20); i++)
                {
                    resultBuilder.Append($"<text>{hash.GetRandom()}</text>");
                }

                return $"<parse>{resultBuilder}</parse>";
            });
        }
    }
}