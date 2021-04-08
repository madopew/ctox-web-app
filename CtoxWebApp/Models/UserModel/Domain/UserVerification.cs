namespace CtoxWebApp.Models.UserModel.Domain
{
    public class UserVerification
    {
        public int Id { get; set; }
        public int UserId { get; set; }
        public virtual User User { get; set; }
        public string Verification { get; set; }
    }
}