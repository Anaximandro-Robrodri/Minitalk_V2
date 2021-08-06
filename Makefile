SERVER = server

CLIENT = client

UTILS = minitalk_utils.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER) : server.o
	$(CC) server.o -o server $(UTILS)

$(CLIENT) : client.o
	$(CC) client.o -o client $(UTILS)
