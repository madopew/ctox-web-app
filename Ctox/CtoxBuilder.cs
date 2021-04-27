using System;
using System.IO;
using System.Runtime.InteropServices;

namespace Ctox
{
    public class CtoxBuilder
    {
        private string basePath = AppDomain.CurrentDomain.BaseDirectory;
        private string name = "ctox";
        private string command = RuntimeInformation.IsOSPlatform(OSPlatform.Windows) ? "ctox.exe" : "ctox";
        private string inputPostfix = "_input";
        private string outputPostfix = "_output";

        public string BasePath
        {
            set => basePath = value;
        }

        public string Name
        {
            set => name = value;
        }

        public string Command
        {
            set => command = value;
        }

        public string InputPostfix
        {
            set => inputPostfix = value;
        }

        public string OutputPostfix
        {
            set => outputPostfix = value;
        }

        public Ctox Build()
        {
            if (!Directory.Exists(basePath))
            {
                throw new ArgumentException("No such directory");
            }

            if (!File.Exists($"{basePath}/{command}"))
            {
                throw new ArgumentException("Program does not exist (probably not compiled)");
            }

            if (inputPostfix.Equals(outputPostfix))
            {
                throw new ArgumentException("Postfixes are the same");
            }

            return new Ctox(basePath, name, command, inputPostfix, outputPostfix);
        }
    }
}