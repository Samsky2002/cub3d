/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:56:49 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 19:17:57 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_distance(t_var *var)
{
	var->horiz_distance = 0;
	var->vert_distance = 0;
	if (var->found_horiz)
		var->horiz_distance = distance_between_points(var->player_x, \
				var->player_y, var->horiz_wall_hit_x, var->horiz_wall_hit_y);
	else
		var->horiz_distance = INT_MAX;
	if (var->found_vert)
		var->vert_distance = distance_between_points(var->player_x, \
				var->player_y, var->vert_wall_hit_x, var->vert_wall_hit_y);
	else
		var->vert_distance = INT_MAX;
}

void	get_final_info(t_var *var)
{
	var->ray->was_vert = 0;
	var->ray->was_horiz = 0;
	if (var->horiz_distance >= var->vert_distance)
	{
		var->ray->wall_hit_x = var->vert_wall_hit_x;
		var->ray->wall_hit_y = var->vert_wall_hit_y;
		var->ray->distance = var->vert_distance;
		var->ray->was_vert = 1;
	}
	else
	{
		var->ray->wall_hit_x = var->horiz_wall_hit_x;
		var->ray->wall_hit_y = var->horiz_wall_hit_y;
		var->ray->distance = var->horiz_distance;
		var->ray->was_horiz = 1;
	}
}

void	get_texture(t_var *var)
{
	if (var->ray->was_vert)
	{
		if (var->left)
			var->texture = var->west;
		else if (var->right)
			var->texture = var->east;
	}
	else
	{
		if (var->up)
			var->texture = var->north;
		else if (var->down)
			var->texture = var->south;
	}
}

void	get_vert_intersec(t_var *var)
{
	while (var->next_x >= 0 && var->next_x <= var->map_width && \
			var->next_y >= 0 && var->next_y <= var->map_height)
	{
		var->x_to_check = var->next_x;
		if (var->left)
			var->x_to_check--;
		var->y_to_check = var->next_y;
		if (check_player_on_wall(var, var->x_to_check, var->y_to_check))
		{
			var->found_vert = 1;
			var->vert_wall_hit_x = var->next_x;
			var->vert_wall_hit_y = var->next_y;
			break ;
		}
		else
		{
			var->next_x += var->x_step;
			var->next_y += var->y_step;
		}
	}
}

void	get_horiz_intersec(t_var *var)
{
	while (var->next_x >= 0 && var->next_x <= var->map_width && \
			var->next_y >= 0 && var->next_y <= var->map_height)
	{
		var->x_to_check = var->next_x;
		var->y_to_check = var->next_y;
		if (var->up)
			var->y_to_check--;
		if (check_player_on_wall(var, var->x_to_check, var->y_to_check))
		{
			var->found_horiz = 1;
			var->horiz_wall_hit_x = var->next_x;
			var->horiz_wall_hit_y = var->next_y;
			break ;
		}
		var->next_x += var->x_step;
		var->next_y += var->y_step;
	}
}
