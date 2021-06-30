#include "http_api.h"
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
