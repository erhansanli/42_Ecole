list =	ft_printf.c \
		ft_printf_help_function.c \

OBJS = $(list:%.c=%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all:$(NAME)

$(NAME) : $(OBJS)
	make -C libft
	cp libft/libft.a libftprintf.a
	ar -rcs $(NAME)	$(OBJS)

%.o	: %.c
	$(CC) $(CFLAGS)	-c $<	-o $@

clean:
	rm -f $(OBJS)
	make clean -C libft


fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

norm:
	@norminette *.[ch]

.PHONY: all clean fclean re norm