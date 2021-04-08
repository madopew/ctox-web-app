﻿namespace CtoxWebApp.Models.UserModel.Domain
{
    public class User
    {
        public int Id { get; set; }
        public string Username { get; set; }
        public string Email { get; set; }
        public string PasswordHash { get; set; }
        public bool Confirmed { get; set; }
        public int? RoleId { get; set; }
        public virtual Role Role { get; set; }
    }
}