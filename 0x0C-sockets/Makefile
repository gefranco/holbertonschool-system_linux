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

SRC2 = http_server.c HTTP_Headers.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = todo_api_2
todo_api_2: $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

SRC3 = http_server.c HTTP_Body_Params.c
OBJ3 = $(SRC3:.c=.o)
NAME3 = todo_api_3
todo_api_3: $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o $(NAME3)

SRC4 = http_server.c HTTP_Create_TODO.c
OBJ4 = $(SRC4:.c=.o)
NAME4 = todo_api_4
todo_api_4: $(OBJ4)
	$(CC) $(CFLAGS) $(OBJ4) -o $(NAME4)

SRC5 = http_server.c HTTP_Retrieve_TODOs.c
OBJ5 = $(SRC5:.c=.o)
NAME5 = todo_api_5
todo_api_5: $(OBJ5)
	$(CC) $(CFLAGS) $(OBJ5) -o $(NAME5)
