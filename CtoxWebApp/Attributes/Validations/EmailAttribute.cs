#nullable enable
using System.ComponentModel.DataAnnotations;
using MimeKit;

namespace CtoxWebApp.Attributes.Validations
{
    public class EmailAttribute : ValidationAttribute
    {
        public override bool IsValid(object? value)
        {
            if (!(value is string vs))
            {
                return false;
            }

            return MailboxAddress.TryParse(vs, out MailboxAddress _);
        }
    }
}