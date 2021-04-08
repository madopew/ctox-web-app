using CtoxWebApp.Models.UserModel.Domain;
using CtoxWebApp.Models.UserModel.View;
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
        public DbSet<UserVerification> UserVerifications { get; set; }
        public DbSet<Role> Roles { get; set; }
    }
}
