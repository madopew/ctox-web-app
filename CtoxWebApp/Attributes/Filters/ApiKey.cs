using System;
using System.Linq;
using CtoxWebApp.DAL;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Controllers;
using Microsoft.AspNetCore.Mvc.Filters;

namespace CtoxWebApp.Attributes.Filters
{
    public class ApiKey : Attribute, IActionFilter
    {
        private AppDbContext dbContext;

        public ApiKey(AppDbContext dbContext)
        {
            this.dbContext = dbContext;
        }
        
        public void OnActionExecuting(ActionExecutingContext context)
        {
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

            var exists = dbContext.Apis.Any(a => a.Key.Equals(context.HttpContext.Request.Headers["x-api-key"]));
            if (!exists)
            {
                context.Result = new UnauthorizedResult();
            }
        }

        public void OnActionExecuted(ActionExecutedContext context)
        {
        }
    }
}