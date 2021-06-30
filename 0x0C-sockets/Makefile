CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3

SRC0 = http_server.c HTTP_Request.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = todo_api_0
todo_api_0: $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)


SRC1 = http_server.c HTTP_Query.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = todo_api_1
todo_api_1: $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)
