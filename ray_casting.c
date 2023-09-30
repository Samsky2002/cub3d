/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:57:07 by oakerkao          #+#    #+#             */
/*   Updated: 2023/09/30 17:54:45 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = 2 * M_PI + angle;
	return (angle);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1), (y2 - y1) * (y2 - y1));
}

void	ray_cast(t_var	*var, double angle)
{
	double	x_intersec;
	double	y_intersec;
	double	x_step;
	double	y_step;
	double	down;
	double	up;
	double	right;
	double	left;
	double	next_x;
	double	next_y;

	down = 0;
	up = 0;
	right = 0;
	left = 0;
	/////////////////////////////////////////////////////////////////
	//				horizontal ray_cast                           //
	/////////////////////////////////////////////////////////////////
	if (angle > 0 && angle < M_PI)
		down = 1;
	else
		up = 1;
	if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
		right = 1;
	else
		left = 1;
	// y and x intersec
	y_intersec = floor(var->player_y / SIZE) * SIZE;
	if (down)
		y_intersec += SIZE;
	x_intersec = var->player_x + (y_intersec - var->player_y) / tan(angle);

	//DDA(var, var->player_x, var->player_y, x_intersec, y_intersec);
	//return ;
	// y and x step 
	y_step = SIZE;
	if (up)
		y_step *= -1;
	x_step = SIZE / tan(angle);
	if (left && x_step > 0)
		x_step *= -1;
	else if (right && x_step < 0)
		x_step *= -1;

	// next_x and next_y
	next_x = x_intersec;
	next_y = y_intersec;
	if (up)
		next_y--;
	double	horiz_wall_hit_x = 0;
	double	horiz_wall_hit_y = 0;
	double	horiz_distance = 0;
	while (next_x > 0 && next_x < SIZE * 10 && next_y > 0 && next_y < SIZE * 10)
	{
		if (check_player_on_wall(var, next_x, next_y))
		{
			horiz_wall_hit_x = next_x;
			horiz_wall_hit_y = next_y;
			break ;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
			i++;
		}
	}
	/////////////////////////////////////////////////////////////////
	//				end											   //
	/////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	//				vertical ray_cast							   //
	/////////////////////////////////////////////////////////////////
	
	//x and y intersec
	x_intersec = floor(var->player_x / SIZE) * SIZE;
	if (right)
		x_intersec += SIZE;
	y_intersec = var->player_y + (x_intersec - var->player_x) * tan(angle);

	// x and y step
	x_step = SIZE;
	if (left)
		x_step *= -1;
	y_step = SIZE * tan(angle);
	if (up && y_step > 0)
		y_step *= -1;
	else if (down && y_step < 0)
		y_step *= -1;

	// next_x and next_y
	next_x = x_intersec;
	next_y = y_intersec;
	if (left)
		next_x--;
	/////////////////////////////////////////////////////////////////
	//				end											   //
	/////////////////////////////////////////////////////////////////
	double	vert_wall_hit_x = 0;
	double	vert_wall_hit_y = 0;
	double	vert_distance = 0;


	while (next_x > 0 && next_x < SIZE * 10 && next_y > 0 && next_y < SIZE * 10)
	{
		if (check_player_on_wall(var, next_x, next_y))
		{
			vert_wall_hit_x = next_x;
			vert_wall_hit_y = next_y;
			break ;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
			i++;
		}
	}

	if (horiz_wall_hit_x)
	{
		horiz_distance = distance_between_points(var->player_x, var->player_y, horiz_wall_hit_x, horiz_wall_hit_y);
	}
	else
		horiz_distance = 10000;
	if (vertical_wall_hit_x)
	{
		vert_distance = distance_between_points(var->player_x, var->player_y, horiz_wall_hit_x, horiz_wall_hit_y);
	}
	else
		vert_distance = 10000;
}

void	cast_all_rays(t_var *var)
{
	t_ray	ray;
	int	i;
	double	angle;

	i = 0;
	angle = var->rotation_angle - (FOV/ 2);
	while (i < RAY_NUM)
	{
		angle = normalize_angle(angle);
		ray_cast(var, angle);
		//DDA(var, var->player_x, var->player_y, var->player_x + cos(angle) * 25, var->player_y + sin(angle) * 25);
		//break ;
		angle += (FOV / RAY_NUM);
		i++;
	 }
}
