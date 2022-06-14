NAME = so_long

CC = cc

INCS = -I.

CFLAGS = -Wall -Wextra -Werror -Imlx $(INCS)

SRCS = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

AR = ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

bonus: $(NAME)

re: fclean all

.PHONY: all clean fclean re
