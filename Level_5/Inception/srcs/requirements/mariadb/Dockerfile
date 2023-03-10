FROM alpine:3.16

RUN apk add mariadb
# downloads and installs mariadb
RUN /etc/init.d/mariadb setup
RUN rc-update add mariadb default 
# Makes sure the DB is started when machine is started (Will be running in a VM)
RUN apk add mariadb-client
RUN mysql -u root

# is this correct? need to read up more on Dockerfiles and MariaDB.
# How to install MariaDB without nginx?