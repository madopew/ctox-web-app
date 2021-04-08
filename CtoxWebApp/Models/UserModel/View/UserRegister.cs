using System.ComponentModel.DataAnnotations;
using CtoxWebApp.Attributes.Validations;

namespace CtoxWebApp.Models.UserModel.View
{
    public class UserRegister
    {
        [Required(ErrorMessage = "Username should be filled")]
        [StringLength(60, MinimumLength = 3, ErrorMessage = "Username length should be between 3 and 60")]
        [RegularExpression("[a-zA-Z]+", ErrorMessage = "Username should consist only of letters")]
        [UniqueUsername(ErrorMessage = "Username is taken")]
        public string Username { get; set; }
        
        [Required(ErrorMessage = "Email should be filled")]
        [DataType(DataType.EmailAddress)]
        [EmailAddress(ErrorMessage = "Email is not valid")]
        [UniqueEmail(ErrorMessage = "Email is taken")]
        public string Email { get; set; }
        
        [Required(ErrorMessage = "Password should be filled")]
        [DataType(DataType.Password)]
        [StringLength(500, MinimumLength = 6, ErrorMessage = "Password should be at least 6 length")]
        [StrongPassword(PasswordHas.Digit | PasswordHas.Lowercase | PasswordHas.Uppercase, ErrorMessage = "Password should contain a digit, lowercase and uppercase letter")]
        public string Password { get; set; }
    }
}