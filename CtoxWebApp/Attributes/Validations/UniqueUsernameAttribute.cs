using System;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using CtoxWebApp.DAL;
using Microsoft.Extensions.DependencyInjection;

namespace CtoxWebApp.Attributes.Validations
{
    public class UniqueUsernameAttribute : ValidationAttribute
    {
        protected override ValidationResult? IsValid(object? value, ValidationContext validationContext)
        {
            if (value is null)
            {
                return new ValidationResult(null);
            }

            var context = validationContext.GetService<AppDbContext>();
            var vs = value.ToString();

            if (context?.Users.FirstOrDefault(u => u.Username.Equals(vs, StringComparison.Ordinal)) != null)
            {
                return new ValidationResult(null);
            }
            
            return ValidationResult.Success;
        }
    }
}