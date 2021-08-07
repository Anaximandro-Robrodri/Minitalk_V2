# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 13:54:21 by robrodri          #+#    #+#              #
#    Updated: 2021/08/07 11:29:17 by robrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

OBJS_S = server.o

OBJS_C = client.o

UTILS = minitalk_utils.c

CC = gcc

RM = rm -rf

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJS_S)
	$(CC) $(FLAGS) $(OBJS_S) -o $(SERVER) $(UTILS)

$(CLIENT) : $(OBJS_C)
	$(CC) $(FLAGS) $(OBJS_C) -o $(CLIENT) $(UTILS)

$(OBJS_S) : server.c minitalk.h
	$(CC) $(FLAGS) -c server.c

$(OBJS_C) : client.c minitalk.h
	$(CC) $(FLAGS) -c client.c

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

PHONY: all clean fclean re
	
