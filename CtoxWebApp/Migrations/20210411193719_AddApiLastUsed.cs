using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace CtoxWebApp.Migrations
{
    public partial class AddApiLastUsed : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Left",
                table: "Apis");

            migrationBuilder.AddColumn<DateTime>(
                name: "LastUsed",
                table: "Apis",
                type: "datetime(6)",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified));
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "LastUsed",
                table: "Apis");

            migrationBuilder.AddColumn<int>(
                name: "Left",
                table: "Apis",
                type: "int",
                nullable: false,
                defaultValue: 0);
        }
    }
}
