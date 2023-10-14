/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:49 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 12:45:13 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "cub3d.h"
# define SIZE 100 
# define HEIGHT 748
# define WIDTH 1024 
# define FOV 60 * (M_PI / 180)

typedef struct s_color_c
{
    int c1;
    int c2;
    int c3;
} t_color_c;

typedef struct s_color_f
{
    int f1;
    int f2;
    int f3;
} t_color_f;

typedef struct s_parser
{
    t_list  *list;
    t_list  *file;
    char **map;
    char *no;
    char *so;
    char *we;
    char *ea;
    int error;
    t_color_c ccolor;
    t_color_f fcolor;
    int len_map;
    char player;
    int count;
    int count_we;
    int count_so;
    int count_ea;
    int count_no;
    int incr;
    int count_player;
} t_parser;

typedef struct s_ray
{
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	int			was_vert;
	int			was_horiz;
}	t_ray;

typedef struct s_var
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	t_ray			*ray;
	t_list			*lst;
	t_parser		parser;
	char			**map;
	double			fov;
	int				test_x;
	int				test_y;
	double			player_x;
	double			player_y;
	int				size;
	double			rotation_angle;
	double			angle;
	int				map_width;
	int				map_height;
	uint32_t		*list;
	int				up;
	int				down;
	int				left;
	int				right;
	double			horiz_wall_hit_x;
	double			horiz_wall_hit_y;
	int				found_horiz;
	double			vert_wall_hit_x;
	double			vert_wall_hit_y;
	int				found_vert;
	double			x_intersec;
	double			y_intersec;
	double			x_step;
	double			y_step;
	double			next_x;
	double			next_y;
	double			x_to_check;
	double			y_to_check;
	double			horiz_distance;
	double			vert_distance;
	int				texture_offset_x;
	int				texture_offset_y;
	int				wall_top_pixel;
	int				wall_bottom_pixel;
	float			prep_distance;
	float			distance_proj_plane;
	float			projected_wall_height;
	float			wall_stripe_height;
}	t_var;

// main
void		init_var(t_var	*var, char *file);
uint32_t	rgba_to_color(uint8_t red, uint8_t green, \
		uint8_t blue, uint8_t alpha);

//dda
void		DDA(t_var *var, int X0, int Y0, int X1, int Y1, int color);

// drawing
void		my_keyhook(void *param);

// drawing_utils
void		draw_line(t_var *var);
void		draw_map(t_list *lst, mlx_image_t *img, t_var *var);
void		draw_player(t_list *lst, mlx_image_t *img, t_var *var);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// get_map
t_list		*put_map(char *file);

// get_x_y
int			get_x(t_list *lst);
int			get_y(t_list *lst);

// map_check
int			check_player_on_wall(t_var *var, double x, double y);

// raycasting
void		cast_all_rays(t_var *var);

//ray_casting_utils
double		distance_between_points(double x1, double y1, double x2, double y2);
double		normalize_angle(double angle);
void		ray_view(t_var *var, double angle);
void		get_distance(t_var *var);
void		get_final_info(t_var *var);
void		get_texture(t_var *var);
void		get_vert_intersec(t_var *var);
void		get_horiz_intersec(t_var *var);

//cub3d_utils
char		**put_twod_array(t_list *lst);
char		*char_join(char *str, char c);

//ray_utils
t_ray		*new_ray(double wall_hit_x, double wall_hit_y, double distance);
void		add_ray(t_ray **ray, t_ray *new);

// render
void		render(t_var *var, int x, double angle);

// textures
void		get_textures(t_var *var);
// oussama
void	keyhook_utils(t_var *var);

int check_file(char *str);
void line_by_line(char *file, t_parser *parser);
void map(t_parser *parser);
void check_tab(t_parser *parser);
void free_cub(t_parser *parser,int i);
void initialize_value(t_parser *parser);
void part_error();
int check_file(char *str);
int check_extension(char *str);
void check_color_and_floor_digit(t_parser *parser);
int check_wall(char *str);
void check_another_chara(char *str);
void check_file_line(t_parser *parser);
void check_char(char *str, t_parser *parser);
char *take_path(t_parser *parser, char *str);
void check_rep_path(t_parser *parser);
void take_color(t_parser *parser, char *str, char c);
void take_string_color(t_parser *parser, char *str, char c);
void char_to_int(t_parser *parser, char *str, char c, int j);
void cieling_struct(t_parser *parser, char *str, char c, int j);
void take_string_color(t_parser *parser, char *str, char c);
void	take_color(t_parser *parser, char *str, char c);
void	check_last_first_line(t_parser *parser);
int	check_if_wall(char *str);
int	check_char_map(char *str, t_parser *parser);
void	parser(char *file, t_var *var);
char    **put_twod_array(t_list *lst);
char	*char_join(char *str, char c);
#endif
