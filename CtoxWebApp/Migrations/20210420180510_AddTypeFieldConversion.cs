using Microsoft.EntityFrameworkCore.Migrations;

namespace CtoxWebApp.Migrations
{
    public partial class AddTypeFieldConversion : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "Type",
                table: "Conversions",
                type: "int",
                nullable: false,
                defaultValue: 0);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Type",
                table: "Conversions");
        }
    }
}
