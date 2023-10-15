CC = cc

NAME = cub3D

CFLAGS =  -Wall -Werror -Wextra 

PARSER = parser/map.c \
 		 parser/parser.c \
		 parser/line_by_line.c \
		 parser/check_tab.c \
		 parser/free_cub.c \
		 parser/initialize_values.c \
		 parser/check_ext_file.c \
		 parser/check_floor_ceiling.c \
		 parser/check_line_by_line.c \
		 parser/check_cara_without_map.c \
		 parser/colors.c

ENGINE = engine/cub3d_utils.c \
		 engine/ray_view.c \
		 engine/map_check.c \
		 engine/get_x_y.c \
		 engine/drawing.c \
		 engine/drawing_utils.c \
		 engine/ray_casting.c \
		 engine/ray_casting_utils.c \
		 engine/ray_utils.c \
		 engine/render.c \
		 engine/textures.c \
		 engine/render_utils.c
		 #engine/dda.c \

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
