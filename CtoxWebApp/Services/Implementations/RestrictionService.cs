using System;
using CtoxWebApp.Models.ApiModel.Domain;
using CtoxWebApp.Models.UserModel.Domain;
using Microsoft.Extensions.Configuration;

namespace CtoxWebApp.Services.Implementations
{
    public class RestrictionService
    {
        private readonly TimeSpan[] timeouts;
        private readonly int[] maxSizes;
        
        public RestrictionService(IConfiguration configuration)
        {
            var names = Enum.GetNames(typeof(Role));
            timeouts = new TimeSpan[names.Length];
            maxSizes = new int[names.Length];

            for (int i = 0; i < names.Length; i++)
            {
                timeouts[i] = TimeSpan.FromMinutes(Convert.ToDouble(configuration[$"Restrictions:Timeouts:{names[i]}"]));
                maxSizes[i] = Convert.ToInt32(configuration[$"Restrictions:Sizes:{names[i]}"]);
            }
        }

        public bool IsAllowedTimeout(Api api)
        {
            var diff = DateTime.Now - api.LastUsed;
            return diff > timeouts[(int) api.User.Role];
        }

        public bool IsAllowedSize(Api api, int size)
        {
            return size <= maxSizes[(int) api.User.Role];
        }
    }
}