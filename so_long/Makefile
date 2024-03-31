YELLOW="\033[0;33m"
RED="\033[1;31m"
GREEN='\033[3;32m'
NONE='\033[0m'

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror #-ImlxLib  -g3 -fsanitize=address

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
	@$(MD) $(OBJFILE)

$(OBJFILE)/%.o : src/%.c Makefile so_long.h keys.h
	@$(CC) -s $(CFLAGS) -I$(MLX) -c $< -o $@

$(NAME): $(OBJS) Makefile
	@$(CC) -s $(OBJS) $(CFLAGS) -L$(MLX) $(FMS) -o $(NAME)
	@echo $(NONE) $(GREEN)"       >Compiled< $(NAME) " $(NONE)

mlx:
	@make -s -C $(MLX) >/dev/null 2>&1
	@echo $(NONE) $(YELLOW)"       >Compiling...<" $(NONE)

clean:
	@$(RM) $(OBJFILE)

fclean: clean
	@$(RM) $(NAME)
	@echo $(NONE) $(RED)"       >Removing< $(NAME)" $(NONE)

re: fclean all

.PHONY: all clean fclean re mlx
