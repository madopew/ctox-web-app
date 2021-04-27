using System.Threading.Tasks;

namespace CtoxWebApp.Services.Interfaces
{
    public interface IParseAsyncService
    {
        Task<string> ParseAsync(string content);
    }
}