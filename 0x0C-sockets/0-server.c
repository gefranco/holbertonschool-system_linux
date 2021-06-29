#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

/**
 * main - entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	int server_socket;
	struct sockaddr_in server_addr;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(12345);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

	while (1)
		listen(server_socket, 5);

	return (0);
}
