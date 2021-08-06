SERVER = server

CLIENT = client

UTILS = minitalk_utils.c

CC = gcc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER) : server.o
	$(CC) server.o -o server $(UTILS)

$(CLIENT) : client.o
	$(CC) client.o -o client $(UTILS)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

PHONY: all clean fclean re
	
