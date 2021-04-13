using System;
using System.Security.Cryptography;
using System.Text;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations
{
    public class HashService: IHashService
    {
        public string GetHash(string content)
        {
            var data = Encoding.UTF8.GetBytes(content);
            return GetHash(data);
        }

        public string GetHashSafe(string content)
        {
            var data = Encoding.UTF8.GetBytes(content);
            return GetHashSafe(data);
        }

        public string GetHash(byte[] data)
        {
            var sha = new SHA256CryptoServiceProvider();
            var enc = sha.ComputeHash(data);
            return Convert.ToBase64String(enc);
        }

        public string GetHashSafe(byte[] data)
        {
            var sha = new SHA256CryptoServiceProvider();
            var enc = sha.ComputeHash(data);
            return Convert.ToBase64String(enc).TrimEnd('=').Replace('+', '-').Replace('/', '_');
        }

        public string GetRandom()
        {
            var data = new byte[8];
            var rnd = new Random();
            rnd.NextBytes(data);
            return GetHashSafe(data);
        }
    }
}