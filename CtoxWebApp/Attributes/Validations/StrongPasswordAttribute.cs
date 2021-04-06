using System;
using System.ComponentModel.DataAnnotations;

namespace CtoxWebApp.Attributes.Validations
{
    [Flags]
    public enum PasswordHas
    {
        None = 0,
        Uppercase = 1,
        Lowercase = 2,
        Digit = 4,
        Special = 8,
    }

    public class StrongPasswordAttribute : ValidationAttribute
    {
        private readonly PasswordHas props;
        
        public StrongPasswordAttribute(PasswordHas props)
        {
            this.props = props;
        }

        public override bool IsValid(object? value)
        {
            if (value is null)
            {
                return false;
            }

            var vs = value.ToString();
            return (Score(vs) & props) == props;
        }

        private PasswordHas Score(string value)
        {
            PasswordHas result = PasswordHas.None;
            foreach (var c in value)
            {
                if (!result.HasFlag(PasswordHas.Uppercase) && char.IsUpper(c))
                {
                    result |= PasswordHas.Uppercase;
                    continue;
                }
                
                if (!result.HasFlag(PasswordHas.Lowercase) && char.IsLower(c))
                {
                    result |= PasswordHas.Lowercase;
                    continue;
                }
                
                if (!result.HasFlag(PasswordHas.Digit) && char.IsDigit(c))
                {
                    result |= PasswordHas.Digit;
                    continue;
                }
                
                if (!result.HasFlag(PasswordHas.Special) && char.IsSymbol(c))
                {
                    result |= PasswordHas.Special;
                    continue;
                }
            }

            return result;
        }
    }
}