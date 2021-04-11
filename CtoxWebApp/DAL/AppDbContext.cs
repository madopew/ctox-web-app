using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Models.UserModel.Domain;
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
        public DbSet<PasswordRestore> PasswordRestores { get; set; }
        public DbSet<Api> Apis { get; set; }
    }
}
