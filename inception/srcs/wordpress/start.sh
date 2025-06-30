#!/bin/sh

echo "=== START.SH is running ==="

# Wait for MariaDB to be ready
echo "Waiting for MariaDB..."
while ! nc -z mariadb 3306; do
  sleep 1
done
echo "MariaDB is ready."
# Make PHP-FPM listen on all interfaces (not just localhost)
sed -i 's|^listen = 127.0.0.1:9000|listen = 0.0.0.0:9000|' /etc/php81/php-fpm.d/www.conf


cd /var/www/html

# Download WordPress if not already installed
if [ ! -f "wp-config.php" ]; then
  echo "Downloading WordPress..."
  curl -O https://wordpress.org/latest.tar.gz
  tar -xzf latest.tar.gz --strip-components=1
  rm latest.tar.gz

  echo "Generating wp-config.php..."
  wp config create \
    --dbname=$DB_NAME \
    --dbuser=$DB_USER \
    --dbpass=$DB_PASS \
    --dbhost=mariadb \
    --path=/var/www/html \
    --skip-check \
    --allow-root

  echo "Installing WordPress..."
  wp core install \
    --url=$DOMAIN \
    --title="Inception Site" \
    --admin_user=$DB_ADMIN \
    --admin_password=$DB_ADMIN_PASS \
    --admin_email=admin@example.com \
    --skip-email \
    --allow-root
fi

chown -R www-data:www-data /var/www/html

# Start PHP-FPM
exec php-fpm81 -F
