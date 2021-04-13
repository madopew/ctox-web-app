using System;
using System.IO;
using System.IO.Compression;
using System.Text;
using CtoxWebApp.Services.Interfaces;

namespace CtoxWebApp.Services.Implementations
{
    public class GzipCompressService: IStringCompressService
    {
        public string Compress(string content)
        {
            string result;
            using (var so = new MemoryStream())
            {
                using (var gzip = new GZipStream(so, CompressionMode.Compress))
                {
                    using (var si = new MemoryStream(Encoding.UTF8.GetBytes(content)))
                    {
                        si.CopyTo(gzip);
                    }
                }

                result = Convert.ToBase64String(so.ToArray());
            }

            return result;
        }

        public string Decompress(string content)
        {
            string result;
            using (var si = new MemoryStream(Convert.FromBase64String(content)))
            {
                using (var gzip = new GZipStream(si, CompressionMode.Decompress))
                {
                    using (var so = new MemoryStream())
                    {
                        gzip.CopyTo(so);
                        result = Encoding.UTF8.GetString(so.ToArray());
                    }
                }
            }

            return result;
        }
    }
}