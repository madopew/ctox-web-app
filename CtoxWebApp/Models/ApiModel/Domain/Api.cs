using System;
using CtoxWebApp.Models.UserModel.Domain;

namespace CtoxWebApp.Models.ApiModel.Domain
{
    public class Api 
    {
        public int Id { get; set; }
        public string Key { get; set; }
        public DateTime LastUsed { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
    }
}