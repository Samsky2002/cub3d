CC = cc

NAME = cub3D

CFLAGS =  -g -fsanitize=address #-Wall -Werror -Wextra 

PARSER = parser/map.c \
		 parser/map_list.c \
		 parser/parser.c \
		 parser/test.c

ENGINE = engine/cub3d_utils.c \
		 engine/get_map.c \
		 engine/map_check.c \
		 engine/get_x_y.c \
		 engine/drawing.c \
		 engine/drawing_utils.c \
		 engine/dda.c \
		 engine/ray_casting.c \
		 engine/ray_casting_utils.c \
		 engine/ray_utils.c \
		 engine/render.c \
		 engine/textures.c \

CFILES = main.c \
		 $(ENGINE) \
		 $(PARSER)

INCLUDE = -Iinclude
OBJECTS = $(CFILES:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C libft
	$(CC) -Iinclude MLX42/build/libmlx42.a  -lglfw -L"/Users/$(USER)/homebrew/opt/glfw/lib" -framework Cocoa -framework OpenGL -framework IOKit $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

%.o : %.c
	$(CC) -Ilibft $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	make clean -C libft
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
