/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:57:07 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 18:55:42 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_cast_vars(t_var *var)
{
	var->x_intersec = 0;
	var->y_intersec = 0;
	var->x_step = 0;
	var->y_step = 0;
	var->next_x = 0;
	var->next_y = 0;
	var->x_to_check = 0;
	var->y_to_check = 0;
}

void	ray_cast_vertical(t_var *var, double angle)
{
	var->found_vert = 0;
	var->vert_wall_hit_x = 0;
	var->vert_wall_hit_y = 0;
	init_ray_cast_vars(var);
	var->x_intersec = floor(var->player_x / SIZE) * SIZE;
	if (var->right)
		var->x_intersec += SIZE;
	var->y_intersec = var->player_y + \
				(var->x_intersec - var->player_x) * tan(angle);
	var->x_step = SIZE;
	if (var->left)
		var->x_step *= -1;
	var->y_step = SIZE * tan(angle);
	if (var->up && var->y_step > 0)
		var->y_step *= -1;
	else if (var->down && var->y_step < 0)
		var->y_step *= -1;
	var->next_x = var->x_intersec;
	var->next_y = var->y_intersec;
	get_vert_intersec(var);
}

void	ray_cast_horizontal(t_var *var, double angle)
{
	var->found_horiz = 0;
	var->horiz_wall_hit_x = 0;
	var->horiz_wall_hit_y = 0;
	init_ray_cast_vars(var);
	var->y_intersec = floor(var->player_y / SIZE) * SIZE;
	if (var->down)
		var->y_intersec += SIZE;
	var->x_intersec = var->player_x + \
				(var->y_intersec - var->player_y) / tan(angle);
	var->y_step = SIZE;
	if (var->up)
		var->y_step *= -1;
	var->x_step = SIZE / tan(angle);
	if (var->left && var->x_step > 0)
		var->x_step *= -1;
	else if (var->right && var->x_step < 0)
		var->x_step *= -1;
	var->next_x = var->x_intersec;
	var->next_y = var->y_intersec;
	get_horiz_intersec(var);
}

void	ray_cast(t_var	*var, double angle)
{
	ray_view(var, angle);
	ray_cast_horizontal(var, angle);
	ray_cast_vertical(var, angle);
	get_distance(var);
	get_final_info(var);
	get_texture(var);
}

void	cast_all_rays(t_var *var)
{
	int		i;
	double	angle;

	i = 0;
	angle = var->rotation_angle - (FOV / 2);
	while (i < WIDTH)
	{
		angle = normalize_angle(angle);
		ray_cast(var, angle);
		render(var, i, angle);
		angle += (FOV / WIDTH);
		i++;
	}
}
