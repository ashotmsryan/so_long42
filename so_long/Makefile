NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -ImlxLib  -g3 -fsanitize=address

SRCS = $(wildcard src/*.c)

OBJFILE = objs

MLX = ./mlxLib

OBJS = $(patsubst src/%.c, $(OBJFILE)/%.o, $(SRCS))

RM = rm -rf

FMS = -lmlx -framework OpenGL -framework AppKit

MD = mkdir -p

ifeq ($(shell uname -s), Linux)
	MLX = minilibx-linux
	FMS = -lmlx -lm -lX11 -lXext
endif

all: mlx $(OBJFILE) $(NAME)

$(OBJFILE) :
	$(MD) $(OBJFILE)

$(OBJFILE)/%.o : src/%.c Makefile so_long.h keys.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile
	$(CC) $(OBJS) $(CFLAGS) -L$(MLX) $(FMS) -o $(NAME)

mlx:
	@make -C $(MLX)

clean:
	$(RM) $(OBJFILE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
