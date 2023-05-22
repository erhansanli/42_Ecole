NAME = push_swap

SRCS =	./sources/control.c \
		./sources/ft_split.c \
		./sources/help_functions.c \
		./sources/operations_fnc_mutual.c \
		./sources/operations_functions_a.c \
		./sources/operations_functions_b.c \
		./sources/push_swap_free.c \
		./sources/main.c \
		./sources/sort_big.c \
		./sources/sort_small.c
			
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re