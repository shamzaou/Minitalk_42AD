NAME = minitalk

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

SERVER_SRC = server.c toolbox.c

CLIENT_SRC = client.c toolbox.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(NAME)

$(NAME): server client

server: $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o server

$(SERVER_OBJ): $(SERVER_SRC)
	$(CC) $(FLAGS) -c $(SERVER_SRC)

client: $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o client

$(CLIENT_OBJ): $(CLIENT_SRC)
	$(CC) $(FLAGS) -c $(CLIENT_SRC)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -f server client

re: fclean all
