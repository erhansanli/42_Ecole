list =	ft_bzero.c \
		ft_memset.c \
			
OBJS = $(list:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all:$(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS)  -c $<	-o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

norm:
	@norminette *.[ch]

.PHONY: clean fclean all re norm