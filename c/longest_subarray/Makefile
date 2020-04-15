# exam Makefile

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -I../../libft/include -L../../libft -lft

SRCS := longest_subarray.c
NAME := a.out

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(NAME)

re : clean all

.PHONY : all clean re


