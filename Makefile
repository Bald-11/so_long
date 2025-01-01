CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRC = main.c get_next_line.c get_next_line_utils.c map.c map2.c map3.c \
	utils.c error.c init_vars.c init.c free.c sprites.c hooks.c anim.c \
	player.c ft_itoa.c ft_printf.c ft_printf_utils.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L/usr/include/minilibx-linux/ -lmlx -lXext -lX11 -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all