/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:54:48 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/11 11:24:06 by oakerkao         ###   ########.fr       */
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

void	render(t_var *var, int x, double angle)
{
	float	distance_proj_plane;
	float	projected_wall_height;
	float	prep_distance;
	float	wall_stripe_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	/*colors and shit*/
	int		pix;
	int		texture_offset_x;
	int		texture_offset_y;
	int	distance_from_top = 0;

	prep_distance = var->ray->distance * cos(angle - var->rotation_angle);
	distance_proj_plane = (WIDTH / 2) * tan(FOV / 2);
	projected_wall_height = (SIZE * 2 / prep_distance) * distance_proj_plane;
	wall_stripe_height = (int)projected_wall_height;
	wall_top_pixel = (HEIGHT / 2) - (wall_stripe_height / 2);
	wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
	wall_bottom_pixel = (HEIGHT / 2) + (wall_stripe_height / 2);
	wall_bottom_pixel = wall_bottom_pixel > HEIGHT ? HEIGHT : wall_bottom_pixel;
	int	y;
	if (var->ray->was_vert)
		texture_offset_x = (int)var->ray->wall_hit_y % SIZE;
	else
		texture_offset_x = (int)var->ray->wall_hit_x % SIZE;
	y = wall_top_pixel;
	while (y < wall_bottom_pixel)
	{
		distance_from_top = y + (wall_stripe_height / 2) - (HEIGHT / 2);
		texture_offset_y = distance_from_top * (float)(var->texture->height) / wall_stripe_height; 
		pix = (var->texture->width * texture_offset_y + texture_offset_x) * var->texture->bytes_per_pixel;
		//color = get_color(var, pix);
		mlx_put_pixel(var->img, x, y, get_color(var, pix));
		y++;
	}
	// exit(0);
	//mlx_put_pixel(var->img, x, y, ft_pixel(215, 138, 118, 255));
}
