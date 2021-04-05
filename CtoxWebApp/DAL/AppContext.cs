using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using CtoxWebApp.Models;
using Microsoft.EntityFrameworkCore;

namespace CtoxWebApp.DAL
{
    public class AppContext : DbContext
    {
        public AppContext(DbContextOptions<AppContext> options)
            : base(options)
        {
        }

        public DbSet<User> Users { get; set; }
    }
}
