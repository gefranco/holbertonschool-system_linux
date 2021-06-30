#include "http_api.h"

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

	setbuf(stdout, NULL);
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
