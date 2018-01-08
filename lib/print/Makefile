##
## Makefile for Makefile in /home/chenne_a/rendu/Piscine_C_J10/lib/my
## 
## Made by Arthur Chennetier
## Login   <chenne_a@epitech.net>
## 
## Started on  Fri Oct  9 10:38:18 2015 Arthur Chennetier
## Last update Fri Dec 18 17:10:42 2015 Arthur Chennetier
##

SRC	= my_putchar.c \
	  my_putchar_va.c \
          my_put_nbr_va.c \
          my_putstr_va.c \
          my_strlen.c \
	  my_put_unva.c \
	  my_put_nbr_base16.c \
	  my_put_nbr_base2.c \
	  my_put_nbr_base16maj.c \
	  my_put_nbr_base8.c \
	  my_putstr_S.c \
	  my_put_nbr_base8S.c \
	  my_printf.c \
	  my_putstr.c \
	  long_long.c

RM	= rm -f

OBJ	= $(SRC:.c=.o)

CC	= gcc

TEMP	= $(SRC:.c=.c~)

MLIB	= ar rc

CFLAGS	+= -W -Wall -Werror -Wextra

NAME	= libprint.a

PREP	= ranlib

MY	= my.h

all: $(NAME)

$(NAME):	$(OBJ)
	$(MLIB) $(NAME) $(OBJ)
	$(PREP) $(NAME)

clean: 
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean:		clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
