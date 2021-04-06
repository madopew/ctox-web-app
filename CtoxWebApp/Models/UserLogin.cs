using System.ComponentModel.DataAnnotations;
using CtoxWebApp.Attributes.Validations;

namespace CtoxWebApp.Models
{
    public class UserLogin
    {
        public string Username { get; set; }
        
        [DataType(DataType.Password)]
        public string Password { get; set; }
    }
}