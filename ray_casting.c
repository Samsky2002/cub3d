/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:57:07 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/06 19:46:17 by oakerkao         ###   ########.fr       */
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

void	ray_cast(t_var	*var, double angle, t_ray *ray)
{
	float	x_intersec;
	float	y_intersec;
	float	x_step;
	float	y_step;
	int		down;
	int		up;
	int		right;
	int		left;
	float	next_x;
	float	next_y;
	int		found_horiz = 0;
	float	horiz_wall_hit_x = 0;
	float	horiz_wall_hit_y = 0;
	float	horiz_distance = 0;

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
	if (angle < M_PI * 0.5 || angle > 1.5 * M_PI)
		right = 1;
	else
		left = 1;

	// y and x intersec
	y_intersec = floor(var->player_y / TWOD_SIZE) * TWOD_SIZE;
	if (down)
		y_intersec += TWOD_SIZE;
	x_intersec = var->player_x + (y_intersec - var->player_y) / tan(angle);

	// y and x step 
	y_step = TWOD_SIZE;
	if (up)
		y_step *= -1;
	x_step = TWOD_SIZE / tan(angle);
	if (left && x_step > 0)
		x_step *= -1;
	else if (right && x_step < 0)
		x_step *= -1;

	// next_x and next_y
	next_x = x_intersec;
	next_y = y_intersec;
	while (next_x >= 0 && next_x <= var->map_width && next_y >= 0 && next_y <= var->map_height)
	{
		float	x_to_check = next_x;
		float	y_to_check = next_y + (up ? -1 : 0);
		if (check_player_on_wall(var, x_to_check, y_to_check))
		{
			found_horiz = 1;
			horiz_wall_hit_x = next_x;
			horiz_wall_hit_y = next_y;
			break ;
		}
		next_x += x_step;
		next_y += y_step;
	}
	/////////////////////////////////////////////////////////////////
	//				end											   //
	/////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	//				vertical ray_cast							   //
	/////////////////////////////////////////////////////////////////
	
	//x and y intersec
	x_intersec = floor(var->player_x / TWOD_SIZE) * TWOD_SIZE;
	if (right)
		x_intersec += TWOD_SIZE;
	y_intersec = var->player_y + (x_intersec - var->player_x) * tan(angle);

	// x and y step
	x_step = TWOD_SIZE;
	if (left)
		x_step *= -1;
	y_step = TWOD_SIZE * tan(angle);
	if (up && y_step > 0)
		y_step *= -1;
	else if (down && y_step < 0)
		y_step *= -1;

	// next_x and next_y
	next_x = x_intersec;
	next_y = y_intersec;
	float	vert_wall_hit_x = 0;
	float	vert_wall_hit_y = 0;
	int		found_vert = 0;
	float	vert_distance = 0;

	while (next_x >= 0 && next_x <= var->map_width && next_y >= 0 && next_y <= var->map_height)
	{
		float x_to_check = next_x + (left ? -1 : 0);
		float y_to_check = next_y;
		if (check_player_on_wall(var, x_to_check, y_to_check))
		{
			found_vert = 1;
			vert_wall_hit_x = next_x;
			vert_wall_hit_y = next_y;
			break ;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
		}
	}
	/////////////////////////////////////////////////////////////////
	//				end											   //
	/////////////////////////////////////////////////////////////////
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance = 0;


	ray->was_vert = 0;
	ray->was_horiz = 0;
	if (found_horiz)
		horiz_distance = distance_between_points(var->player_x, var->player_y, horiz_wall_hit_x, horiz_wall_hit_y);
	else
		horiz_distance = 10000000;
	if (found_vert)
		vert_distance = distance_between_points(var->player_x, var->player_y, vert_wall_hit_x, vert_wall_hit_y);
	else
		vert_distance = 1000000;
	if (horiz_distance >= vert_distance)
	{
		wall_hit_x = vert_wall_hit_x;
		wall_hit_y = vert_wall_hit_y;
		distance = vert_distance;
		ray->was_vert = 1;
	}
	else
	{
		wall_hit_x = horiz_wall_hit_x;
		wall_hit_y = horiz_wall_hit_y;
		distance = horiz_distance;
		ray->was_horiz = 1;
	}
	ray->wall_hit_x = wall_hit_x;
	ray->wall_hit_y = wall_hit_y;
	ray->distance = distance;
}

void	render(t_var *var, int x, double angle, t_ray *ray)
{
	float	distance_proj_plane;
	float	projected_wall_height;
	float	prep_distance;
	int		wall_stripe_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	/*colors and shit*/
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;
	int		pix;
	int		texture_offset_x;
	int		texture_offset_y;

	prep_distance = ray->distance * cos(angle - var->rotation_angle);
	distance_proj_plane = (WIDTH / 2) * tan(FOV / 2);
	projected_wall_height = 2 * (TWOD_SIZE / prep_distance) * distance_proj_plane;
	wall_stripe_height = (int)projected_wall_height;
	wall_top_pixel = (HEIGHT / 2) - (wall_stripe_height / 2);
	wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
	wall_bottom_pixel = (HEIGHT / 2) + (wall_stripe_height / 2);
	wall_bottom_pixel = wall_bottom_pixel > HEIGHT ? HEIGHT : wall_bottom_pixel;
	int	y;
	y = wall_top_pixel;
	if (ray->was_vert)
		texture_offset_x = (int)ray->wall_hit_y % TWOD_SIZE;
	else
		texture_offset_x = (int)ray->wall_hit_x % var->texture->width;
	while (y < wall_bottom_pixel)
	{
		texture_offset_y = (y - wall_top_pixel) * ((float)var->texture->height / wall_stripe_height);
		pix = (var->texture->width * texture_offset_y + texture_offset_x) * 4;
		red = var->texture->pixels[pix];
		green = var->texture->pixels[pix + 1];
		blue = var->texture->pixels[pix + 2];
		alpha = var->texture->pixels[pix + 3];
		mlx_put_pixel(var->img, x, y, ft_pixel(red, green, blue, alpha));
		y++;
	}
	//mlx_put_pixel(var->img, x, y, ft_pixel(215, 138, 118, 255));
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
		ray_cast(var, angle, &var->ray[i]);
		render(var, i, angle, &var->ray[i]);
		DDA(var, var->player_x, var->player_y, var->ray[i].wall_hit_x, var->ray[i].wall_hit_y);
		angle += (FOV / WIDTH);
		i++;
	 }
}
