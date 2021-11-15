##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/ls.c	\
		src/my_ls_l.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_put_nbr.c	\
		src/id.c	\
		src/my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: clean fclean re all

