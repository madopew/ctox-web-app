using System.ComponentModel.DataAnnotations;

namespace CtoxWebApp.Models.UserModel.View
{
    public class UserLogin
    {
        public string Username { get; set; }
        
        [DataType(DataType.Password)]
        public string Password { get; set; }
    }
}