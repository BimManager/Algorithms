# exam Makefile

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

SRCS := find_pivot.c
NAME := a.out

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -rf $(NAME)

re : clean all

.PHONY : all clean re


