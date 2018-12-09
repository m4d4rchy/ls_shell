##
## EPITECH PROJECT, 2017
## Makefiles
## File description:
## 
##

LDFLAGS =	lib/libmy.a

CC	= 	gcc

NAME	= 	my_ls

SRC 	=	src/main.c\
		src/my_ls_l.c\
		src/my_fonction.c

OBJS 	= 	$(SRCS:.c=.o)


all: 		$(NAME)

$(NAME):	$(OBJS)
		make -C lib/my/
		$(CC) -o $(NAME) $(SRC) -W -Wall -Werror -Wextra $(LDFLAGS)

clean:
		$(RM) $(OBJS)
		make -f lib/my/Makefile clean
fclean: 	clean
		$(RM) $(NAME)
re: 		fclean all

.PHONY: 	all clean fclean re
