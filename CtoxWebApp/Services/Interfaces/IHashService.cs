namespace CtoxWebApp.Services.Interfaces
{
    public interface IHashService
    {
        public string GetHash(string content);
        public string GetHash(byte[] data);
        public string GetHashSafe(string content);
        public string GetHashSafe(byte[] data);
        public string GetRandom();
    }
}