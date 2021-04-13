using System.Threading.Tasks;

namespace CtoxWebApp.Services.Interfaces
{
    public interface IEmailSenderService
    {
        Task SendEmailAsync(string receiverName, string receiverEmail, string body);
    }
}