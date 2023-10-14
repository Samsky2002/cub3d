/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:53:10 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 10:37:43 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	keyhook_utils(t_var *var)
{
	// mlx_delete_image(var->mlx, var->img);
	// var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	//draw_map(var->lst, var->img, var);
	//draw_player(var->lst, var->img, var);
	cast_all_rays(var);
	// mlx_image_to_window(var->mlx, var->img, 0, 0);
}

void	go_up(t_var *var, int speed)
{
	double	new_x;
	double	new_y;

	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
	{
		new_x = var->player_x + cos(var->rotation_angle) * speed;
		new_y = var->player_y + sin(var->rotation_angle) * speed;
		if (!check_player_on_wall(var, new_x, new_y) && \
				!(check_player_on_wall(var, var->player_x, new_y) &&\
					check_player_on_wall(var, new_x, var->player_y)))
		{
			var->player_x = new_x; 
			var->player_y = new_y; 
		}
	}

}

void	go_down(t_var *var, int speed)
{
	double	new_x;
	double	new_y;	

	if (mlx_is_key_down(var->mlx, MLX_KEY_S))
	{
		new_x = var->player_x - cos(var->rotation_angle) * speed;
		new_y = var->player_y - sin(var->rotation_angle) * speed;
		if (!check_player_on_wall(var, new_x, new_y) && \
				!(check_player_on_wall(var, var->player_x, new_y) &&\
					check_player_on_wall(var, new_x, var->player_y)))
		{
			var->player_x = new_x; 
			var->player_y = new_y; 
		}
	}
}

void	go_left(t_var *var, int speed)
{
	double	new_x;
	double	new_y;	

	if (mlx_is_key_down(var->mlx, MLX_KEY_A))
	{
		new_x = var->player_x - cos(var->rotation_angle + M_PI / 2) * speed;
		new_y = var->player_y - sin(var->rotation_angle + M_PI / 2) * speed;
		if (!check_player_on_wall(var, new_x, new_y) && \
				!(check_player_on_wall(var, var->player_x, new_y) &&\
					check_player_on_wall(var, new_x, var->player_y)))
		{
			var->player_x = new_x; 
			var->player_y = new_y;
			printf("%d\n", (int)var->player_x / SIZE);
			printf("%d\n", (int)var->player_y / SIZE);
		}
	}
}

void	go_right(t_var *var, int speed)
{
	double	new_x;
	double	new_y;	

	if (mlx_is_key_down(var->mlx, MLX_KEY_D))
	{
		new_x = var->player_x + cos(var->rotation_angle + M_PI / 2) * speed;
		new_y = var->player_y + sin(var->rotation_angle + M_PI / 2) * speed;
		if (!check_player_on_wall(var, new_x, new_y) && \
				!(check_player_on_wall(var, var->player_x, new_y) \
					&& check_player_on_wall(var, new_x, var->player_y)))
		{
			var->player_x = new_x;
			var->player_y = new_y;
		}
	}
}

void	clear_map(t_var *var)
{
	int	i;
	int	j;

	// free the window and call another one
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(var->img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

void	my_keyhook(void* param)
{
	t_var	*var;
	double	new_x;
	double	new_y;	
	int	speed = 7;

	var = param;
	clear_map(var);
	go_up(var, speed);
	go_down(var, speed);
	go_left(var, speed);
	go_right(var, speed);
	if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
		var->rotation_angle -= 3 * (M_PI / 180);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
		var->rotation_angle += 3 * (M_PI / 180);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
		exit(0);
	keyhook_utils(var);
}
	//DDA(var, var->player_x / SIZE * 20, var->player_y / SIZE * 20, var->player_x / SIZE * 20 + cos(var->rotation_angle) * 20, var->player_y / SIZE * 20 + sin(var->rotation_angle) * 20, ft_pixel(215, 138, 118, 255));
