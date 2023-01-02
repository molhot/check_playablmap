NAME = gnl

SRCS = basic_check.c get_next_line.c main.c check_fill.c\
		libft/ft_strchr.c libft/ft_strjoin.c libft/ft_strlen.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS2:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I includes

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)
	rm -rf a.out

re: fclean all

.PHONY:			all clean fclean re bonus