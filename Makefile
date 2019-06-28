	##
## EPITECH PROJECT, 2017
## PSU_navy_2017
## File description:
## Makefile
##

CFLAGS  +=	-Wall -Werror -Wextra -W
CFLAGS  +=	-I./include

ROOT		=		./

#	Sources path
F_SRC		=		$(ROOT)src/

#	Binary name
NAME		=		navy

#	Debug sources
SRC		=		$(F_SRC)main.c


SRC		+=		$(F_SRC)get_next_line.c			\
				$(F_SRC)game.c				\
				$(F_SRC)get_str_from_binary.c		\
				$(F_SRC)show.c				\
				$(F_SRC)map.c

SRC		+=		$(F_SRC)utils/my_strcpy.c		\
				$(F_SRC)utils/my_strcat.c		\
				$(F_SRC)utils/my_strlen.c		\
				$(F_SRC)utils/coordinate_converter.c	\
				$(F_SRC)utils/my_putchar.c		\
				$(F_SRC)utils/my_putstr.c		\
				$(F_SRC)utils/binary_converter.c	\
				$(F_SRC)utils/my_getnbr.c		\
				$(F_SRC)utils/before_send_converter.c	\
				$(F_SRC)utils/my_put_nbr.c		\
				$(F_SRC)utils/my_strdup.c		\
				$(F_SRC)utils/my_int_to_str.c

SRC		+=		$(F_SRC)connection/handler_signal.c	\
				$(F_SRC)connection/send_signal.c	\
				$(F_SRC)connection/start_client.c	\
				$(F_SRC)connection/start_server.c	\
				$(F_SRC)connection/wait_server.c

#	Compile every source file to .o
OBJ		=		$(SRC:.c=.o)

#	Compiler
CC		=		gcc -std=gnu++11

#	Compilation flags
CFLAGS		+=		-Wall -Werror -Wextra -pedantic -std=gnu99	\
				-I $(ROOT)include/

#	Call compilation rule
all:				$(NAME)

#	Compile every file then pack them all !
$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

#	Compile with g3 flag
debug:				fclean $(OBJ)
				$(CC) -o $(NAME) $(CFLAGS) -g3 $(OBJ) $(LDFLAGS)

#	Clean object type sources
clean:
				rm -f $(OBJ)

#	Clean binary
fclean:					clean
				rm -f $(NAME)

#	Clean all then compile
re:				fclean all

.PHONY:				all clean fclean re

