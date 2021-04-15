namespace CtoxWebApp.Models.ApiModel.View
{
    public enum ParseType
    {
        Xml, 
        Json
    }
    
    public class ParseRequestUi
    {
        public string Data { get; set; }
        public ParseType Type { get; set; }
    }
}