/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:53:10 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/15 09:59:11 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_up(t_var *var, int speed)
{
	double	new_x;
	double	new_y;

	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
	{
		new_x = var->player_x + cos(var->rotation_angle) * speed;
		new_y = var->player_y + sin(var->rotation_angle) * speed;
		if (!check_player_on_wall(var, new_x, new_y) && \
				!(check_player_on_wall(var, var->player_x, new_y) && \
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
				!(check_player_on_wall(var, var->player_x, new_y) && \
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
				!(check_player_on_wall(var, var->player_x, new_y) && \
					check_player_on_wall(var, new_x, var->player_y)))
		{
			var->player_x = new_x; 
			var->player_y = new_y;
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

void	my_keyhook(void *param)
{
	t_var	*var;
	int		speed;

	speed = 7;
	var = param;
	clear_map(var);
	go_up(var, speed);
	go_down(var, speed);
	go_left(var, speed);
	go_right(var, speed);
	if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
		var->rotation_angle -= 2 * (M_PI / 180);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
		var->rotation_angle += 2 * (M_PI / 180);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
	{
		//cleaning(var);
		exit(0);	
	}
	cast_all_rays(var);
}
