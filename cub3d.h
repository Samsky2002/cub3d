/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:49 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/06 19:34:17 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# define TWOD_SIZE 32 
# define SIZE 64 
# define HEIGHT 1000 
# define WIDTH 1500 
# define FOV 60 * (M_PI / 180) 
# define RAY_NUM 320 // window width / ray width
// map_width_height 640 640 

typedef struct	s_ray
{
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		was_vert;
	int		was_horiz;
	struct s_ray	*next;
} t_ray;

typedef struct	s_var
{
	double	player_x;
	double	player_y;
	double	rotation_angle;
	double	angle;
	int	map_width;
	int	map_height;
	t_ray	*ray;
	t_list	*lst;
	mlx_image_t	*img;
	mlx_t	*mlx;
	mlx_texture_t	*texture;
	uint32_t	*list;
} t_var;


// main
void	init_var(t_var	*var, char *file);
uint32_t rgba_to_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

//dda
void	DDA(t_var *var, int X0, int Y0, int X1, int Y1);

// drawing
void	my_keyhook(void *param);

// drawing_utils
void	draw_line(t_var *var);
void	draw_map(t_list *lst, mlx_image_t *img);
void	draw_player(t_list *lst, mlx_image_t *img, t_var *var);
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// get_map
t_list	*put_map(char *file);

// get_x_y
int	get_x(t_list *lst);
int	get_y(t_list *lst);

// map_check
int	check_player_on_wall(t_var *var, double x, double y);

// raycasting
void	cast_all_rays(t_var *var);

//cub3d_utils
char	**put_twod_array(t_list *lst);

//ray_utils
t_ray	*new_ray(double wall_hit_x, double wall_hit_y, double distance);
void	add_ray(t_ray **ray, t_ray *new);


#endif
