using System;
using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;

namespace CtoxService
{
    public class Ctox
    {
        private readonly string command;
        
        public Ctox(string command)
        {
            if (!File.Exists(command))
            {
                throw new ArgumentException("File doesn't exist. Check if it's compiled.");
            }

            this.command = command;
        }

        public string Parse(string content)
        {
            using var process = new Process();
            process.StartInfo.FileName = command;
            process.StartInfo.RedirectStandardInput = true;
            process.StartInfo.RedirectStandardOutput = true;
            process.Start();
            process.StandardInput.Write(content);
            process.StandardInput.Close();
            var result = process.StandardOutput.ReadToEnd();
            process.WaitForExit();
            return result;
        }

        public Task<string> ParseAsync(string content)
        {
            return Task.Run(() => Parse(content));
        }
    }
}