# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 18:44:22 by anaraujo          #+#    #+#              #
#    Updated: 2022/12/07 19:34:12 by anaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = ./srcs/client.c
SERVER_SRCS = ./srcs/server.c

CLIENT_SRCS_BONUS = ./srcs/client_bonus.c
SERVER_SRCS_BONUS = ./srcs/server_bonus.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft
$(SERVER): $(SERVER_OBJS)  $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS)  $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_OBJS_BONUS)  $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS_BONUS) $(LIBFT) -o server
$(CLIENT_BONUS): $(CLIENT_OBJS_BONUS)  $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) $(LIBFT) -o client

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
	rm -rf $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVER) $(CLIENT)
	rm -rf $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all