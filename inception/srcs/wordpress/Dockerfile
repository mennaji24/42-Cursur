FROM alpine:3.19

# Install PHP + FPM + required extensions
RUN apk update && apk add --no-cache \
    php81 \
    php81-fpm \
    php81-mysqli \
    php81-curl \
    php81-json \
    php81-mbstring \
    php81-dom \
    php81-opcache \
    php81-phar \
    php81-session \
    php81-fileinfo \
    php81-tokenizer \
    php81-simplexml \
    php81-pecl-imagick \
    php81-xml \
    php81-cli \
    curl \
    bash \
    tar \
    less \
    shadow \
    net-tools
    
RUN ln -s /usr/bin/php81 /usr/bin/php

# Create www-data user if missing
RUN adduser -u 82 -D -S -G www-data www-data || true

# Install WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/html

COPY ./start.sh /start.sh
RUN chmod +x /start.sh

ENTRYPOINT ["/start.sh"]
