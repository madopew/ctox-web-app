using System;
using System.Buffers.Text;
using System.Security.Cryptography;
using System.Text;

namespace CtoxWebApp.Services
{
    public class HashService
    {
        public string GetHash(string content)
        {
            var data = Encoding.UTF8.GetBytes(content);
            var sha = new SHA256CryptoServiceProvider();
            var enc = sha.ComputeHash(data);
            return Convert.ToBase64String(enc);
        }
    }
}