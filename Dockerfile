FROM gcc:8 as compiler
COPY ./CtoxService/Library/. /app
WORKDIR /app
RUN gcc -o ctox c_lexer.lex.c c_parser.tab.c

FROM mcr.microsoft.com/dotnet/sdk:5.0 AS build
WORKDIR /app
COPY . .
RUN dotnet sln remove CtoxTests/CtoxTests.csproj
RUN rm -rf ./CtoxTests
RUN dotnet restore
RUN dotnet publish -c Release -o out

FROM mcr.microsoft.com/dotnet/aspnet:3.1
WORKDIR /app
COPY --from=build /app/out .
COPY --from=compiler /app/ctox ./ctox
EXPOSE 5000
ENV ASPNETCORE_URLS "http://*:5000"
ENTRYPOINT ["dotnet", "CtoxWebApp.dll"]