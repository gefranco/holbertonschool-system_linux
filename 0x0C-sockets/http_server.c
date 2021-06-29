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

/**
 * main - entry point.
 *
 * Return: 0 on success 1 otherwise.
 */
int main(void)
{
	int server_socket;
	struct sockaddr_in server_addr;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(server_socket,
			(struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("bind error\n");
		return (1);
	}

	if (listen(server_socket, 5) == -1)
	{
		printf("listen error\n");
		return (1);
	}

	printf("Server listening on port %d\n", PORT);

	while (1)
	{
		accept_msgs(server_socket);
	}
	close(server_socket);
	return (0);
}

/**
 * accept_msgs - proccess client requests.
 * @server_socket: server socket
 * Return: 0 on success 1 otherwise.
 */
int accept_msgs(int server_socket)
{
	int client_socket, client_size;
	struct sockaddr_in client_addr;
	char client_req[REQ_SIZE] = {0};

	char *delim = " \t\r\n";
	char *method, *path, *version;
	size_t b_read;

	client_size = sizeof(client_addr);
	client_socket = accept(server_socket,
				(struct sockaddr *)&client_addr,
				((socklen_t *) &client_size));
	if (client_socket == -1)
	{
		printf("error\n");
		return (1);
	}
	printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

	client_req[0] = 0;
	b_read = recv(client_socket, &client_req, REQ_SIZE, 0);

	if (b_read > 0)
	{
		client_req[b_read] = 0;
		printf("Raw request: \"%s\"\n", client_req);

		method = strtok(client_req, delim);
		path = strtok(NULL, delim);
		version = strtok(NULL, delim);

		printf("Method: %s\n", method);
		printf("Path: %s\n", path);
		printf("Version: %s\n", version);
	}
	send(client_socket, RESPONSE_200, strlen(RESPONSE_200), 0);

	close(client_socket);
	return (0);
}
