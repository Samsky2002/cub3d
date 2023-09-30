/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:53:10 by oakerkao          #+#    #+#             */
/*   Updated: 2023/09/30 16:04:46 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	my_keyhook(void* param)
{
	t_var	*var;
	double	new_x;
	double	new_y;	

	var = param;
	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
	{
		printf("UP\n");
		new_x = var->player_x + cos(var->rotation_angle) * 3;
		new_y = var->player_y + sin(var->rotation_angle) * 3;
		if (check_player_on_wall(var, new_x, new_y))
		{
			printf("you hit a wall\n");
			return ; 
		}
		var->player_x += cos(var->rotation_angle) * 3;
		var->player_y += sin(var->rotation_angle) * 3;
		draw_map(var->lst, var->img);
		draw_player(var->lst, var->img, var);
		cast_all_rays(var);
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_A))
	{
		new_x = var->player_x + cos(var->rotation_angle) * 3;
		new_y = var->player_y + sin(var->rotation_angle) * 3;
		if (check_player_on_wall(var, new_x, new_y))
		{
			printf("you hit a wall\n");
			return ; 
		}
		var->player_x += cos(var->rotation_angle - M_PI / 2) * 3;
		var->player_y += sin(var->rotation_angle - M_PI / 2) * 3;
		draw_map(var->lst, var->img);
		draw_player(var->lst, var->img, var);
		cast_all_rays(var);
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_S))
	{
		printf("DOWN\n");
		new_x = var->player_x - cos(var->rotation_angle) * 3;
		new_y = var->player_y - sin(var->rotation_angle) * 3;
		if (check_player_on_wall(var, new_x, new_y))
		{
			printf("you hit a wall\n");
			return ; 
		}
		var->player_x -= cos(var->rotation_angle) * 3;
		var->player_y -= sin(var->rotation_angle) * 3;
		draw_map(var->lst, var->img);
		draw_player(var->lst, var->img, var);
		cast_all_rays(var);
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_D))
	{
		printf("RIGHT\n");
		new_x = var->player_x + cos(var->rotation_angle) * 3;
		new_y = var->player_y + sin(var->rotation_angle) * 3;
		if (check_player_on_wall(var, new_x, new_y))
		{
			printf("you hit a wall\n");
			return ; 
		}
		var->player_x += cos(var->rotation_angle + M_PI / 2) * 3;
		var->player_y += sin(var->rotation_angle + M_PI / 2) * 3;
		draw_map(var->lst, var->img);
		draw_player(var->lst, var->img, var);
		cast_all_rays(var);
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
	{
		var->rotation_angle -= 2 * (M_PI / 180);
		draw_map(var->lst, var->img);
		draw_player(var->lst, var->img, var);
		cast_all_rays(var);

	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
	{
		var->rotation_angle += 2 * (M_PI / 180);
		draw_map(var->lst, var->img);
		draw_player(var->lst, var->img, var);
		cast_all_rays(var);
	}
}
