##
## Makefile for pushswap in /home/champi_t/rendu/CPE_2015_Pushswap
## 
## Made by theo champion
## Login   <champi_t@epitech.net>
## 
## Started on  Tue Nov 17 18:48:59 2015 theo champion
## Last update Mon Jan 25 01:54:02 2016 theo champion
##

CC	= cc

RM	= rm -f

SRC	= main.c	\
          cases.c	\
          list.c	\
          print_menu.c	\
          functions.c

NAME	= my_select

OBJS	= $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRC) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
