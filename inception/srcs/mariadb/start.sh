#!/bin/sh

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB..."
    mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql
fi

# Ensure envsubst works
echo "Expanding init.sql..."
envsubst < /docker-entrypoint-initdb.d/init.sql > /tmp/init.sql || {
    echo "envsubst failed"; exit 1;
}

echo "Starting MariaDB on 0.0.0.0:3306"
exec mysqld --user=mysql --init-file=/tmp/init.sql
