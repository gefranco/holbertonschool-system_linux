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

int main()
{
	int server_socket;
	struct sockaddr_in server_addr;

	int client_socket, client_size;
	struct sockaddr_in client_addr;
	char client_req[256];

	char *delim = " \t\r\n";
	char *method, *path, *version;


	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	
	if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("bind error\n");
		return (1);
	}	
	
	if(listen(server_socket, 5) == -1)
	{
		printf("listen error\n");
		return (1);
	}
	
	printf("Server listening on port %d\n", PORT);
	
	client_size = sizeof(client_addr);
        
	while (1)
	{
	
		client_socket = accept(server_socket, 
				(struct sockaddr *)&client_addr,
				((socklen_t *) &client_size));
		if (client_socket == -1)
		{
			printf("error\n");
			return 1;
		}
		printf("Client Connected: %s\n", inet_ntoa(client_addr.sin_addr));
	
		recv(client_socket, &client_req, sizeof(client_req), 0);
		printf("Raw Request: \"%s\"\n", client_req);
		
		method = strtok(client_req, delim);
		path = strtok(NULL, delim);
		version = strtok(NULL, delim);
		
		printf("Method: %s\n", method);
		printf("Path: %s\n", path);
		printf("Version: %s\n", version);

		send(client_socket, RESPONSE_200, sizeof(RESPONSE_200), 0);
	
	
		close(client_socket);
	}
	close(server_socket);
	return 0;
}
