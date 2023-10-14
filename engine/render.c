/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:54:48 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 12:44:46 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_color(t_var *var, int pix)
{
	uint32_t	color;
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;

	red = var->texture->pixels[pix++];
	green = var->texture->pixels[pix++];
	blue = var->texture->pixels[pix++];
	alpha = var->texture->pixels[pix];
	color = ft_pixel(red, green, blue, alpha);
	return (color);
}

void	color_top(t_var *var, int x)
{
	int	y;

	y = 0;
	while (y < var->wall_top_pixel)
	{
		mlx_put_pixel(var->img, x, y, ft_pixel(var->parser.ccolor.c1, var->parser.ccolor.c2, var->parser.ccolor.c3, 255));
		y++;
	}

}

void	color_bottom(t_var *var, int x)
{
	int	y;

	y = var->wall_bottom_pixel;
	while (y < HEIGHT)
	{
		mlx_put_pixel(var->img, x, y, ft_pixel(var->parser.fcolor.f1, var->parser.fcolor.f2, var->parser.fcolor.f3, 255));
		y++;
	}

}

void	get_offset_x(t_var *var)
{
	if (var->ray->was_vert)
		var->texture_offset_x = (int)var->ray->wall_hit_y % SIZE;
	else
		var->texture_offset_x = (int)var->ray->wall_hit_x % SIZE;
}

void	render(t_var *var, int x, double angle)
{
	int		pix;
	int	distance_from_top = 0;
	int	y;

	var->ray->distance = var->ray->distance <= 0 ? 2 : var->ray->distance;
	var->prep_distance = var->ray->distance * cos(var->rotation_angle - angle);
	var->distance_proj_plane = (WIDTH / 2) * tan(FOV / 2);
	var->projected_wall_height = (SIZE * 2 / var->prep_distance) * var->distance_proj_plane;
	var->wall_stripe_height = (int)var->projected_wall_height;
	var->wall_top_pixel = (HEIGHT / 2) - (var->wall_stripe_height / 2);
	var->wall_top_pixel = var->wall_top_pixel < 0 ? 0 : var->wall_top_pixel;
	var->wall_bottom_pixel = (HEIGHT / 2) + (var->wall_stripe_height / 2);
	var->wall_bottom_pixel = var->wall_bottom_pixel > HEIGHT ? HEIGHT : var->wall_bottom_pixel;
	color_top(var, x);
	get_offset_x(var);
	y = var->wall_top_pixel;
	// printf("%f\n", (var->wall_stripe_height / 2) - (HEIGHT / 2));
	// exit(0);
	while (y < var->wall_bottom_pixel)
	{
		distance_from_top = y + (var->wall_stripe_height / 2) - (HEIGHT / 2);
		var->texture_offset_y = distance_from_top * (float)(var->texture->height) / var->wall_stripe_height; 
		pix = (var->texture->width * var->texture_offset_y + var->texture_offset_x) * var->texture->bytes_per_pixel;
		mlx_put_pixel(var->img, x, y, get_color(var, pix));
		y++;
	}
	color_bottom(var, x);
}
