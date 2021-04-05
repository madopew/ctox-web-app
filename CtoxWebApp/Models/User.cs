using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace CtoxWebApp.Models
{
    public enum Role
    {
        User,
        Moderator,
    }

    public class User
    {
        public int Id { get; set; }
        public string Username { get; set; }
        public string Email { get; set; }
        public string PasswordHash { get; set; }
        public bool Confirmed { get; set; }
        public Role Role { get; set; }
    }
}