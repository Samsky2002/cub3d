/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:56:49 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/12 11:02:40 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = 2 * M_PI + angle;
	return (angle);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ray_view(t_var *var, double angle)
{
	var->up = 0;
	var->down = 0;
	var->left = 0;
	var->right = 0;
	if (angle > 0 && angle < M_PI)
		var->down = 1;
	else
		var->up = 1;
	if (angle < M_PI * 0.5 || angle > 1.5 * M_PI)
		var->right = 1;
	else
		var->left = 1;
}

void	get_distance(t_var *var)
{
	var->horiz_distance = 0;
	var->vert_distance = 0;
	if (var->found_horiz)
		var->horiz_distance = distance_between_points(var->player_x, var->player_y, \
				var->horiz_wall_hit_x, var->horiz_wall_hit_y);
	else
		var->horiz_distance = INT_MAX;
	if (var->found_vert)
		var->vert_distance = distance_between_points(var->player_x, var->player_y, \
				var->vert_wall_hit_x, var->vert_wall_hit_y);
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
		var->x_to_check = var->next_x + (var->left ? -1 : 0);
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
		var->y_to_check = var->next_y + (var->up ? -1 : 0);
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
