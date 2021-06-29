#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

/**
 * main - Entry point
 * @na: number of arguments
 * @argv: arguments
 * Return: 0 on success 1 otherwise.
 */
int main(int na, char *argv[])
{
	int network_socket;
	struct sockaddr_in server_addr;
	int con_status;

	int port;
	char *host = NULL;

	if (na != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	host = argv[1];
	port = atoi(argv[2]);

	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	if (strcmp(host, "localhost") == 0)
		host = "127.0.0.1";
	server_addr.sin_addr.s_addr = inet_addr(host);

	con_status = connect(network_socket,
				(struct sockaddr *)&server_addr, sizeof(server_addr));

	if (con_status == -1)
	{
		printf("There was an error\n");
		return (1);
	}


	printf("Connected to %s:%s\n", argv[1], argv[2]);

	close(network_socket);
	return (EXIT_SUCCESS);
}
