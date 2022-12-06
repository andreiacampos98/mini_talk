# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 18:44:22 by anaraujo          #+#    #+#              #
#    Updated: 2022/12/06 22:14:01 by anaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = ./srcs/client.c 
SERVER_SRCS = ./srcs/server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT) :
		$(MAKE) -C ./libft
$(SERVER): $(SERVER_OBJS)  $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS)  $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVER) $(CLIENT)

re: fclean all