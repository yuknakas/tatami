NAME	=	tatami
CC		=	gcc -Wall -Wextra -Werror

SRCS	=	srcs/check.c srcs/color.c srcs/init.c srcs/main.c srcs/place.c
OBJS	=	$(SRCS:.c=.o)

RMFLAG	=	rm -rf

all: $(NAME)

$(NAME) = $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.
	$(CC) -c $< -o $@

clean:
	$(RMFLAG) $(OBJS)

fclean: clean
	$(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean fclean re