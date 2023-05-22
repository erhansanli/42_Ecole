NAME	=	philo
SRCS	=	philo.c	set_init.c time.c check.c utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -rf
CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
			
re:	fclean $(NAME)

.PHONY:	all clean fclean re
