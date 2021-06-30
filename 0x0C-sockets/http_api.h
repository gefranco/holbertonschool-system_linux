#ifndef _HTTP_API_
#define _HTTP_API_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define RESPONSE_200 "HTTP/1.1 200 OK\r\n\r\n"
#define REQ_SIZE 8000

int accept_msgs(int server_socket);

#endif
