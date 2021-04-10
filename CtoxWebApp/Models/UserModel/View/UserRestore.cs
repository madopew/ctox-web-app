using System.ComponentModel.DataAnnotations;
using CtoxWebApp.Attributes.Validations;
using Microsoft.AspNetCore.Mvc;

namespace CtoxWebApp.Models.UserModel.View
{
    public class UserRestore
    {
        [Required(ErrorMessage = "Password should be filled")]
        [DataType(DataType.Password)]
        [StringLength(500, MinimumLength = 6, ErrorMessage = "Password should be at least 6 length")]
        [StrongPassword(PasswordHas.Digit | PasswordHas.Lowercase | PasswordHas.Uppercase, ErrorMessage = "Password should contain a digit, lowercase and uppercase letter")]
        public string Password { get; set; }
        
        [Display(Name = "Repeat password")]
        [DataType(DataType.Password)]
        [Compare("Password", ErrorMessage = "Passwords are not equal")]
        public string RepeatPassword { get; set; }
        
        [HiddenInput(DisplayValue = false)]
        public string Restore { get; set; }
    }
}