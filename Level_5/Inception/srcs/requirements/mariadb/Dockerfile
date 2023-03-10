FROM alpine:3.16

RUN apk add mariadb
RUN /etc/init.d/mariadb setup
RUN rc-update add mariadb default
RUN apk add mariadb-client
RUN mysql -u root