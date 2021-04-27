using CtoxService;
using NUnit.Framework;

namespace CtoxTests
{
    [TestFixture]
    public class CtoxServiceTests
    {
        private const string ValidInput = @"int main() { return 0; }";

        private const string ValidOutput =
            @"<program> <function> <prototype> int main ( ) </prototype> <body> <return> 0 </return> </body> </function> </program>";

        private const string InvalidInput = @"int main() { return 0 }";

        private const string InvalidOutput = @"<error>syntax error on line 1</error>";

        [Test]
        public void Parse_ValidInput_ReturnsParsed()
        {
            Assert.AreEqual(ValidOutput,
                new Ctox(@"C:\Users\Madi\source\repos\CtoxWebApp\CtoxService\Library\ctox.exe").Parse(ValidInput));
        }
        
        [Test]
        public void Parse_InvalidInput_ReturnsError()
        {
            Assert.AreEqual(InvalidOutput,
                new Ctox(@"C:\Users\Madi\source\repos\CtoxWebApp\CtoxService\Library\ctox.exe").Parse(InvalidInput));
        }
    }
}