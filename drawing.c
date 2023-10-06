/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:53:10 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/06 17:57:08 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	keyhook_utils(t_var *var)
{
	draw_map(var->lst, var->img);
	draw_player(var->lst, var->img, var);
	cast_all_rays(var);
}

void	my_keyhook(void* param)
{
	t_var	*var;
	double	new_x;
	double	new_y;	
	int	j = 0;
	int	i = 0;

	var = param;
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
	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
	{
		printf("UP\n");
		new_x = var->player_x + cos(var->rotation_angle) * 2;
		new_y = var->player_y + sin(var->rotation_angle) * 2;
		if (!check_player_on_wall(var, new_x, new_y))
		{
			var->player_x += cos(var->rotation_angle) * 2;
			var->player_y += sin(var->rotation_angle) * 2;
		}
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_A))
	{
		printf("LEFT\n");
		new_x = var->player_x - cos(var->rotation_angle + M_PI / 2) * 3;
		new_y = var->player_y - sin(var->rotation_angle + M_PI / 2) * 3;
		if (!check_player_on_wall(var, new_x, new_y))
		{
			var->player_x -= cos(var->rotation_angle + M_PI / 2) * 3;
			var->player_y -= sin(var->rotation_angle + M_PI / 2) * 3;
		}
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_S))
	{
		printf("DOWN\n");
		new_x = var->player_x - cos(var->rotation_angle) * 2;
		new_y = var->player_y - sin(var->rotation_angle) * 2;
		if (!check_player_on_wall(var, new_x, new_y))
		{
			var->player_x -= cos(var->rotation_angle) * 2;
			var->player_y -= sin(var->rotation_angle) * 2;
		}
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_D))
	{
		printf("RIGHT\n");
		new_x = var->player_x + cos(var->rotation_angle + M_PI / 2) * 3;
		new_y = var->player_y + sin(var->rotation_angle + M_PI / 2) * 3;
		if (!check_player_on_wall(var, new_x, new_y))
		{
			var->player_x += cos(var->rotation_angle + M_PI / 2) * 3;
			var->player_y += sin(var->rotation_angle + M_PI / 2) * 3;
		}
	}
	else if (mlx_is_key_down(var->mlx, MLX_KEY_LEFT))
		var->rotation_angle -= 2 * (M_PI / 180);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_RIGHT))
		var->rotation_angle += 2 * (M_PI / 180);
	else if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
		exit(0);
	keyhook_utils(var);
}
