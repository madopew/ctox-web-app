using CtoxWebApp.Attributes.Filters;
using CtoxWebApp.DAL;
using CtoxWebApp.Services.Implementations;
using CtoxWebApp.Services.Interfaces;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.EntityFrameworkCore;

namespace CtoxWebApp
{
    public class Startup
    {
        public Startup(IConfiguration configuration)
        {
            var builder = new ConfigurationBuilder()
                .AddJsonFile("secretsettings.json")
                .AddConfiguration(configuration);

            Configuration = builder.Build();
        }

        private IConfiguration Configuration { get; }

        // This method gets called by the runtime. Use this method to add services to the container.
        public void ConfigureServices(IServiceCollection services)
        {
            services.AddTransient(p => Configuration);
            services.AddTransient<IHashService, HashService>();
            services.AddTransient<IStringCompressService, GzipCompressService>();
            services.AddTransient<ApiKey>();
            services.AddSingleton<IParseAsyncService, ParseAsyncService>();
            services.AddSingleton<IEmailSenderService, EmailSenderService>();
            services.AddSingleton<RestrictionService>();

            services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
                .AddCookie(o =>
                {
                    o.LoginPath = new PathString("/Auth/Login");
                    o.AccessDeniedPath = new PathString("/Home/Index");
                });

            services
                .AddControllersWithViews()
                .AddControllersAsServices()
                .AddRazorRuntimeCompilation();

            var appContextConnection = Configuration.GetConnectionString("AppContext");
            services.AddDbContextPool<AppDbContext>(options =>
                options
                    .UseLazyLoadingProxies()
                    .UseMySql(appContextConnection, ServerVersion.AutoDetect(appContextConnection)));
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }
            else
            {
                app.UseExceptionHandler("/Error");
                app.UseHsts();
            }

            app.UseHttpsRedirection();

            app.UseDefaultFiles();

            app.UseStaticFiles();

            app.UseRouting();

            app.UseAuthentication();
            app.UseAuthorization();

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllerRoute(
                    "verification",
                    "Verify/{verificationString:required}",
                    new { controller = "Auth", action = "Verify" });
                endpoints.MapControllerRoute(
                    "restorepassword",
                    "Reset/{resetString:required}",
                    new { controller = "Auth", action = "Reset" });
                endpoints.MapControllerRoute(
                    name: "default",
                    pattern: "{controller}/{action}"
                );
                endpoints.MapControllers();
            });
        }
    }
}
