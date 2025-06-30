FROM alpine:3.19

RUN apk update && apk add --no-cache nginx openssl

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./start.sh /start.sh
RUN chmod +x /start.sh

ENTRYPOINT ["/start.sh"]
