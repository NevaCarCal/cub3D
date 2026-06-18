NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH = minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

GNL_PATH = get_next_line
PRINTF_PATH = ft_printf
FT_PRINTF_LIB = $(PRINTF_PATH)/libftprintf.a

INCLUDES = -I. -I$(MLX_PATH) -I$(GNL_PATH) -I$(PRINTF_PATH)

CFILES = \
	error_free.c \
	map.c \
	checker.c \
	main.c \
	checker_utils.c \
	ft_init.c \
	ft_move.c \
	flood_fill.c \
	game.c \
	raycast.c \
	libft.c \
	utils.c \
	$(GNL_PATH)/get_next_line.c \
	$(GNL_PATH)/get_next_line_utils.c

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(PRINTF_PATH)

$(NAME): $(MLX_LIB) $(FT_PRINTF_LIB) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(FT_PRINTF_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
