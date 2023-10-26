NAME = so_long

SOURCES = so_long.c \
				./utils/so_long_utils/check_map_utils.c ./utils/so_long_utils/technicals.c \
				./utils/so_long_utils/images.c ./utils/so_long_utils/move_utils.c \
				./utils/so_long_utils/play_game_utils.c ./utils/so_long_utils/put_utils.c \
				./utils/so_long_utils/put_utils_2.c \
				./utils/lib_ft/ft_calloc.c ./utils/lib_ft/ft_itoa.c \
				./utils/lib_ft/ft_split.c ./utils/lib_ft/ft_strjoin.c \
				./utils/lib_ft/ft_strlcpy.c ./utils/lib_ft/ft_strlen.c \
				./utils/lib_ft/ft_printf/ft_printf.c ./utils/lib_ft/ft_printf/ft_putchar.c \
				./utils/lib_ft/ft_printf/ft_puthex.c ./utils/lib_ft/ft_printf/ft_putnbr.c \
				./utils/lib_ft/ft_printf/ft_putptr.c ./utils/lib_ft/ft_printf/ft_putstr.c \
				./utils/lib_ft/ft_printf/ft_putunsig.c

CC = cc

# LINUX FLAGS:

MLXFLAGS = ./MLX42/build/libmlx42.a -I ./MLX42/include/MLX42/MLX42.h -ldl -lglfw -pthread -lm -g3

# MACOS FLAGS:

# MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit ./MLX42/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

CFLAGS = -Wextra -Werror -Wall -g3

OBJECTS = $(SOURCES:.c=.o)

PNAME = -o $(NAME)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(MLXFLAGS) $(CFLAGS) $(PNAME)

clean:
	@rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

play: all
	@./so_long ./maps/map4.ber

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
