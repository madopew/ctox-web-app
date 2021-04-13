namespace CtoxWebApp.Services.Interfaces
{
    public interface IStringCompressService
    {
        string Compress(string content);
        string Decompress(string content);
    }
}