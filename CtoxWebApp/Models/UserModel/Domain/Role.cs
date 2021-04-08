﻿using System.Collections.Generic;

namespace CtoxWebApp.Models.UserModel.Domain
{
    public class Role
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public virtual List<User> Users { get; set; }
    }
}