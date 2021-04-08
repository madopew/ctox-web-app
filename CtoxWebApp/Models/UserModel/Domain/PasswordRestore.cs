namespace CtoxWebApp.Models.UserModel.Domain
{
    public class PasswordRestore
    {
        public int Id { get; set; }
        public string Restore { get; set; }
        public bool Valid { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
    }
}