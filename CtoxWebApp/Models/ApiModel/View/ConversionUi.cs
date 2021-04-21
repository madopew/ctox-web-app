using System.Collections.Generic;
using CtoxWebApp.Models.ApiModel.Domain;

namespace CtoxWebApp.Models.ApiModel.View
{
    public class ConversionUi
    {
        public bool HasKey { get; set; }
        public string Key { get; set; }
        public int Amount { get; set; }
        public IEnumerable<Conversion> Conversions { get; set; }
    }
}