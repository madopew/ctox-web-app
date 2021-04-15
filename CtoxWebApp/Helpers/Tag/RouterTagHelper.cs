using System;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.AspNetCore.Mvc.TagHelpers;
using Microsoft.AspNetCore.Mvc.ViewFeatures;
using Microsoft.AspNetCore.Razor.TagHelpers;

namespace CtoxWebApp.Helpers.Tag
{
    [HtmlTargetElement("a", Attributes = "active-title")]
    [HtmlTargetElement("a", Attributes = "active-class")]
    public class RouterTagHelper : TagHelper
    {
        [ViewContext]
        [HtmlAttributeNotBound]
        public ViewContext ViewContext { get; set; }
        
        [HtmlAttributeName("active-title")]
        public string Title { get; set; }
        
        [HtmlAttributeName("active-class")]
        public string Active { get; set; }

        public override Task ProcessAsync(TagHelperContext context, TagHelperOutput output)
        {
            if (Title is null && !ViewContext.ViewData.ContainsKey("title"))
            {
                throw new ArgumentException("View data should contain title value if no title present");
            }

            var content = output.GetChildContentAsync().Result.GetContent();
            bool condition = Title?.Equals(content) ?? ViewContext.ViewData["title"].Equals(content);

            if (condition)
            {
                var tagBuilder = new TagBuilder("a");
                tagBuilder.AddCssClass(Active ?? "active");
                output.MergeAttributes(tagBuilder);
            }

            return base.ProcessAsync(context, output);
        }
    }
}