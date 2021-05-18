# CToX web app

## Description

Application with web UI and Rest API to parse program written in C99.
It includes:

-   Authorization
-   Authentication
-   REST Api
-   Semi good-looking UI

## Docker

This application is optimized for docker usage.<br>
<b>Warning!</b> Application doesn't use HTTPS, reverse-proxy usage is necessary.

### Environment variables

| Name                          | Description                         | Required | Default |
| ----------------------------- | ----------------------------------- | -------- | ------- |
| ConnectionStrings:AppContext  | Connection string to DBMS           | true     |
| Email:Name                    | Gmail used to send data             | true     |
| Email:Password                | Password for email                  | true     |
| Restrictions:Timeouts:Regular | Timeout in minutes for regular user | false    | 10      |
| Restrictions:Timeouts:Super   | Timeout in minutes for super user   | false    | 1       |
| Restrictions:Timeouts:Admin   | Timeout in minutes for admin user   | false    | 0       |
| Restrictions:Sizes:Regular    | Max size in bytes for regular user  | false    | 512     |
| Restrictions:Sizes:Super      | Max size in bytes for super user    | false    | 4096    |
| Restrictions:Sizes:Admin      | Max size in bytes for admin user    | false    | 10240   |

### docker-compose example

```yaml
version: "3"

services:
    mysql:
        image: mysql:8
        environment:
            - "MYSQL_DATABASE=ctox_db"
            - "MYSQL_ROOT_PASSWORD=12345"
        volumes:
            - mysqldata:/var/lib/mysql

    ctoxweb:
        image: madopew/ctoxwebapp:latest
        depends_on:
            - mysql
        environment:
            - "ConnectionStrings:AppContext=server=mysql; port=3306; database=ctox_db; user=root; password=12345"
            - "Email:Name=email@gmail.com"
            - "Email:Password=strongPassword"
        links:
            - mysql
        volumes:
            - aspnetcorekeys:/root/.aspnet/DataProtection-Keys # data protection keys shared volume
        restart: on-failure # in case mysql not loaded yet

    reverse-proxy:
        image: nginx:latest
        depends_on:
            - ctoxweb
        ports:
            - 80:80
        volumes:
            - ./proxy.conf:/etc/nginx/conf.d/default.conf

volumes:
    mysqldata:
    aspnetcorekeys:
```

## Documentation

Course documenation can be found [here](./Course%20Documentation/paper.pdf)

## Creator

Bakyt Madi, for course project, KSiS, 951007, 2021, Minsk
