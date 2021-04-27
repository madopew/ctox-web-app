using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;

namespace Ctox
{
    public class Ctox
    {
        private readonly string basePath;
        private readonly string name;
        private readonly string command;
        private readonly string inputPostfix;
        private readonly string outputPostfix;

        internal Ctox(string basePath, string name, string command, string inputPostfix, string outputPostfix)
        {
            this.basePath = basePath;
            this.name = name;
            this.command = command;
            this.inputPostfix = inputPostfix;
            this.outputPostfix = outputPostfix;
        }

        public string Parse(string content)
        {
            var inputFile = new FileStream($"{basePath}/{name}{inputPostfix}", FileMode.Create);
            var writer = new StreamWriter(inputFile);
            writer.Write(content);
            writer.Close();
            Process.Start($"{basePath}/{command}", $"< {name}{inputPostfix} > {name}{outputPostfix}");
            var outputFile = new FileStream($"{basePath}/{name}{outputPostfix}", FileMode.Open);
            using var reader = new StreamReader(outputFile);
            return reader.ReadToEnd();
        }

        public Task<string> ParseAsync(string content)
        {
            var inputFile = new FileStream($"{basePath}/{name}{inputPostfix}", FileMode.Create);
            var writer = new StreamWriter(inputFile);
            writer.WriteAsync(content);
            writer.Close();
            Process.Start($"{basePath}/{command}", $"< {name}{inputPostfix} > {name}{outputPostfix}");
            var outputFile = new FileStream($"{basePath}/{name}{outputPostfix}", FileMode.Open);
            using var reader = new StreamReader(outputFile);
            return reader.ReadToEndAsync();
        }
    }
}