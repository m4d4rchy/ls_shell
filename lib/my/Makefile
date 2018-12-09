##
## Makefile
## 
## Made by Benmessahel Yassine
## Login   <yassine.b@epitech.net>
## 
## Started on  Mon Mar 13 14:42:24 2017 Benmessahel Yassine
## Last update Fri Nov  3 20:50:35 2017 Yassine Benmessahel
##

CC	= 	gcc

LDFLAGS	= 	../libmy.a

LSRC	=	*.c

OBJS 	= 	$(LSRC.c=.o)


all: 		$(OBJS)
		$(CC) -c $(LSRC)
		ar rc ../libmy.a *.o

clean:
		rm  lib/my/*.o

fclean: 	clean
		$(RM) $(LDFLAGS)

re: 		fclean all

.PHONY: 	all clean fclean re
