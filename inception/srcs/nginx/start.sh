#!/bin/sh

mkdir -p /etc/ssl/certs /etc/ssl/private

if [ ! -f /etc/ssl/certs/nginx.crt ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/ssl/private/nginx.key \
        -out /etc/ssl/certs/nginx.crt \
        -subj "/C=FR/ST=Paris/L=Paris/O=42/OU=Student/CN=${DOMAIN}"
fi

nginx -g 'daemon off;'
