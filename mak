SRC_SERVER = ./src/server.c

SRC_CLIENT = ./src/client.c

OBJS_SERVER = ${SRC_SERVER:.c=.o}

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

NAME_SERVER = server

NAME_CLIENT = client

#BONUS DEFINITIONS#

SRC_SERVER_BONUS = ./src_bonus/server_bonus.c

SRC_CLIENT_BONUS = ./src_bonus/client_bonus.c

OBJS_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}

OBJS_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}

NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus

#COMPILATION UTILS#

LIBRARY = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#RULES#

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:  norminette libft compile

norminette: 
	@echo "\n *** CHECKING 42 NORMINETTE ***\n"
	@norminette src/
	@norminette src_bonus/

libft: 
	@echo "\n *** COMPILING LIBFT ***\n"
	@${MAKE} -C ./libft

compile: ${NAME_SERVER} ${NAME_CLIENT}

$(NAME_SERVER): ${OBJS_SERVER}
	@echo "\n *** COMPILING SERVER PROGRAM ***\n"
	@${CC} ${OBJS_SERVER} ${LIBRARY} -o ${NAME_SERVER}

$(NAME_CLIENT): ${OBJS_CLIENT}
	@echo "\n *** COMPILING CLIENT PROGRAM ***\n"
	@${CC} ${OBJS_CLIENT} ${LIBRARY} -o ${NAME_CLIENT}

#BONUS RULES#

bonus: norminette libft compile_bonus

compile_bonus: ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

$(NAME_SERVER_BONUS): ${OBJS_SERVER_BONUS}
	@echo "\n *** COMPILING SERVER BONUS PROGRAM ***\n"
	@${CC} ${OBJS_SERVER_BONUS} ${LIBRARY} -o ${NAME_SERVER}

$(NAME_CLIENT_BONUS): ${OBJS_CLIENT_BONUS}
	@echo "\n *** COMPILING CLIENT BONUS PROGRAM ***\n"
	@${CC} ${OBJS_CLIENT_BONUS} ${LIBRARY} -o ${NAME_CLIENT}

#CLEAN RULES#

clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS_SERVER} ${OBJS_CLIENT} 
	@${RM} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}


fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re libft compile norminette


******++


#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

#endif

******

SRCS_CLIENT	= client.c
SRCS_SERVER	= server.c
			
NAME_CLIENT	= client
NAME_SERVER	= server

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC	= gcc
AR = ar rcs
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME_CLIENT) $(NAME_SERVER)

bonus:	all

$(NAME_CLIENT):	$(OBJS_CLIENT)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) -L libft -lft

$(NAME_SERVER):	$(OBJS_SERVER)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) -L libft -lft
		
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:		clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	
re:		fclean all

.PHONY: all, clean, fclean, re, bonus