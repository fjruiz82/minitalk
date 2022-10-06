# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:47:27 by fruiz-ca          #+#    #+#              #
#    Updated: 2022/10/06 11:56:28 by fruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#BASE
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJS_SERVER = ${SRC_SERVER:.c=.o}
OBJS_CLIENT = ${SRC_CLIENT:.c=.o}
NAME_SERVER = server
NAME_CLIENT = client

#BONUS
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c
OBJS_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}
OBJS_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

#OTHERS
NAME = minitalk.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = ./libft/libft.a

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

#BASE
all:		$(NAME)

$(NAME):	$(OBJS_SERVER) $(OBJS_CLIENT)
			@make -C libft/ all
			$(CC) $(CFLAGS) libft/libft.a $(OBJS_SERVER) -o server
			$(CC) $(CFLAGS) libft/libft.a $(OBJS_CLIENT) -o client

bonus:		$(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
			@make -C libft/ all
			$(CC) $(CFLAGS) libft/libft.a $(OBJS_SERVER_BONUS) -o server_bonus
			$(CC) $(CFLAGS) libft/libft.a $(OBJS_CLIENT_BONUS) -o client_bonus

clean:
			$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) client server
			$(RM) client_bonus server_bonus
			make -C libft/ fclean

re:			fclean all

.PHONY: all clean fclean re