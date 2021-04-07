using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using CtoxWebApp.Models;
using Microsoft.EntityFrameworkCore;

namespace CtoxWebApp.DAL
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options)
            : base(options)
        {
        }

        public DbSet<User> Users { get; set; }
        public DbSet<Role> Roles { get; set; }
    }
}
