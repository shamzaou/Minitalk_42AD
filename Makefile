NAME = minitalk

CC = gcc

FLAGS = -Wall -Wextra -Werror

TOOLBOX = toolbox.c

SERVER_SRC = server.c

CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(NAME)

$(NAME): server client

server: $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) $(TOOLBOX:.c=.o) -o server

$(SERVER_OBJ): $(SERVER_SRC) $(TOOLBOX)
	$(CC) $(FLAGS) -c $(SERVER_SRC) $(TOOLBOX)

client: $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) $(TOOLBOX:.c=.o) -o client

$(CLIENT_OBJ): $(CLIENT_SRC) $(TOOLBOX)
	$(CC) $(FLAGS) -c $(CLIENT_SRC) $(TOOLBOX)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(TOOLBOX:.c=.o)

fclean: clean
	rm -f server client

re: fclean all
