NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -ImlxLib  -g3 -fsanitize=address

SRCS = $(wildcard src/*.c)

OBJFILE = objs

MLX = ./mlxLib

OBJS = $(patsubst src/%.c, $(OBJFILE)/%.o, $(SRCS))

RM = rm -rf

MD = mkdir -p

all: mlx $(OBJFILE) $(NAME)

$(OBJFILE) :
	$(MD) $(OBJFILE)

$(OBJFILE)/%.o : src/%.c Makefile so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile
	$(CC) $(OBJS) $(CFLAGS) -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mlx:
	@make -C $(MLX)

clean:
	$(RM) $(OBJFILE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
