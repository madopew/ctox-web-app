using System;
using System.Data.Entity;
using System.Linq;
using CtoxWebApp.DAL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Controllers;
using Microsoft.AspNetCore.Mvc.Filters;

namespace CtoxWebApp.Attributes.Filters
{
    public class ApiKey : Attribute, IActionFilter
    {
        public ApiKey()
        {
        }

        public string Roles { get; set; }

        public void OnActionExecuting(ActionExecutingContext context)
        {
            // ReSharper disable once PossibleNullReferenceException
            if ((context.ActionDescriptor as ControllerActionDescriptor)
                .MethodInfo
                .GetCustomAttributes(typeof(AllowNoApi), false)
                .FirstOrDefault() != null)
            {
                return;
            }

            if (!context.HttpContext.Request.Headers.ContainsKey("x-api-key"))
            {
                context.Result = new UnauthorizedResult();
                return;
            }

            var dbContext = (AppDbContext) context.HttpContext.RequestServices.GetService(typeof(AppDbContext));

            var api = dbContext.Apis
                .Include(a => a.User)
                .FirstOrDefault(a => a.Key.Equals(context.HttpContext.Request.Headers["x-api-key"]));

            if (api is null)
            {
                context.Result = new UnauthorizedResult();
                return;
            }

            if (Roles is null || Roles.Length == 0)
            {
                return;
            }

            foreach (var role in Roles.Split(','))
            {
                if (api.User.Role.ToString().Equals(role))
                {
                    return;
                }
            }

            context.Result = new UnauthorizedResult();
        }

        public void OnActionExecuted(ActionExecutedContext context)
        {
        }
    }
}