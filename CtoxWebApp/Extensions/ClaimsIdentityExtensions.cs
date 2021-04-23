using System;
using System.Linq;
using System.Security.Claims;

namespace CtoxWebApp.Extensions
{
    public static class ClaimsIdentityExtensions
    {
        public static void UpdateClaim(this ClaimsIdentity identity, string type, string value)
        {
            var claim = identity.Claims.FirstOrDefault(c => c.Type.Equals(type));
            if (claim is null)
            {
                throw new InvalidOperationException("Identity doesnt have specified type");
            }
            
            identity.RemoveClaim(claim);
            identity.AddClaim(new Claim(type, value));
        }
    }
}