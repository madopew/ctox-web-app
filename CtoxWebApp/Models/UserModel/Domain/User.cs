﻿namespace CtoxWebApp.Models.UserModel.Domain
{
    public enum Role 
    {
        Regular,
        Super,
        Admin,
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