using System.Text;
using System.Threading.Tasks;
using MailKit.Net.Smtp;
using Microsoft.Extensions.Configuration;
using MimeKit;

namespace CtoxWebApp.Services
{
    public class EmailSenderService
    {
        private readonly string email;
        private readonly string password;

        public EmailSenderService(IConfiguration configuration)
        {
            email = configuration["Email:Name"];
            password = configuration["Email:Password"];
        }

        public async Task SendEmail(string receiverName, string receiverEmail, string body)
        {

            var message = new MimeMessage();
            var from = new MailboxAddress(Encoding.UTF8, "Ctox", email);
            var to = new MailboxAddress(Encoding.UTF8, receiverName, receiverEmail);
            message.From.Add(from);
            message.To.Add(to);
            message.Subject = "Ctox Service Notification.";

            var bodyBuilder = new BodyBuilder
            {
                TextBody = body,
            };
            message.Body = bodyBuilder.ToMessageBody();

            var smtp = new SmtpClient();
            await smtp.ConnectAsync("smtp.gmail.com", 465, true);

            await smtp.AuthenticateAsync(Encoding.UTF8, email, password);

            await smtp.SendAsync(message);
            await smtp.DisconnectAsync(true);
            smtp.Dispose();
        }
    }
}