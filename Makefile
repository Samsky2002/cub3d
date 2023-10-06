CC = cc

NAME = cub3d

CFLAGS = -g -fsanitize=address -O3#-Wall -Werror -Wextra

CFILES = main.c \
		 cub3d_utils.c \
		 get_map.c \
		 map_check.c \
		 get_x_y.c \
		 drawing.c \
		 drawing_utils.c \
		 dda.c \
		 ray_casting.c \
		 ray_utils.c

OBJECTS = $(CFILES:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C libft
	$(CC) -Iinclude MLX42/build/libmlx42.a  -lglfw -L"/Users/$(USER)/homebrew/opt/glfw/lib" -framework Cocoa -framework OpenGL -framework IOKit $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

%.o : %.c
	$(CC) -Ilibft $(CFLAGS) -c $< -o $@

clean :
	make clean -C libft
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
