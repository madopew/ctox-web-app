using System;
using CtoxWebApp.Models.UserModel.Domain;

namespace CtoxWebApp.Models.ApiModel.Domain
{
    public class Conversion
    {
        public int Id { get; set; }
        public DateTime Time { get; set; }
        public string Initial { get; set; }
        public string Result { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
    }
}