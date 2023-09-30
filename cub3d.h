/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:49 by oakerkao          #+#    #+#             */
/*   Updated: 2023/09/30 16:45:46 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# define HEIGHT 1000 
# define WIDTH 1000
# define SIZE 70 
# define P_SIZE 15 
# define FOV 60 * (M_PI / 180) 
# define RAY_NUM 300  // window width / ray width

typedef struct	s_var
{
	double	player_x;
	double	player_y;
	double	rotation_angle;
	double	angle;
	t_list	*lst;
	mlx_image_t	*img;
	mlx_t	*mlx;
} t_var;

typedef struct	s_ray
{
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	struct s_ray	*next;
} t_ray;

// main
void	init(void *param);

//dda
void	DDA(t_var *var, int X0, int Y0, int X1, int Y1);

// drawing
void	my_keyhook(void *param);

// drawing_utils
void	draw_line(t_var *var);
void	draw_map(t_list *lst, mlx_image_t *img);
void	draw_player(t_list *lst, mlx_image_t *img, t_var *var);

// get_map
t_list	*put_map(int fd);

// get_x_y
int	get_x(t_list *lst);
int	get_y(t_list *lst);

// map_check
int	check_player_on_wall(t_var *var, double x, double y);

// raycasting
void	cast_all_rays(t_var *var);

//cub3d_utils
char	**put_twod_array(t_list *lst);


#endif
