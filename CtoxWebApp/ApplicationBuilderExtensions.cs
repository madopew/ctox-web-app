using System.Threading;
using Microsoft.AspNetCore.Builder;
using Microsoft.EntityFrameworkCore;

namespace CtoxWebApp
{
    public static class ApplicationBuilderExtensions
    {
        private const int MaxRetries = 10;
        private const int RetryDelay = 5000;

        public static void EnsureConnected<T>(this IApplicationBuilder app)
            where T : DbContext
        {
            var context = (T) app.ApplicationServices.GetService(typeof(T));

            for (int i = 0; i < MaxRetries; i++)
            {
                if (context.IsConnected())
                {
                    return;
                }
                Thread.Sleep(RetryDelay);
            }

            throw new System.InvalidOperationException("Could not establish connection");
        }

        public static void EnsureMigrated<T>(this IApplicationBuilder app)
            where T : DbContext
        {
            var context = app.ApplicationServices.GetService(typeof(T));
            ((T)context).Database.Migrate();
        }

        private static bool IsConnected(this DbContext context)
        {
            try 
            {
                _ = context.Database.ExecuteSqlRaw("SELECT 1");
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}