# exam Makefile

CC := gcc
#CFLAGS := -Wall -Wextra -Werror -g -I../../libft/include -L../../libft -lft
CFLAGS := -w -g -I../../libft/include -L../../libft -lft \
			 -fsanitize=address -O1 -fno-omit-frame-pointer

SRCS := print_doublon.c
NAME := a.out

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(NAME)

re : clean all

.PHONY : all clean re


