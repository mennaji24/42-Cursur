FROM alpine:3.19

RUN apk update && apk add --no-cache \
    mariadb mariadb-client \
    bash \
    gettext # this provides envsubst

COPY ./start.sh /start.sh
COPY ./my.cnf /etc/my.cnf
COPY ./init.sql /docker-entrypoint-initdb.d/init.sql

RUN chmod +x /start.sh

EXPOSE 3306

ENTRYPOINT ["/start.sh"]