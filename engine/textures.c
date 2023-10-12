/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:45:17 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/10 14:55:29 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(mlx_texture_t	*texture)
{
	if (!texture)
		return (1);
	if (texture->height != 100)
	{
		printf("Wrong size\n");
		return (1);
	}
	if (texture->height != texture->width)
	{
		printf("Wrong size\n");
		return (1);
	}
	return (0);
}

void	get_textures(t_var *var)
{
	var->north = NULL;
	var->south = NULL;
	var->east = NULL;
	var->west = NULL;
	var->north = mlx_load_png("./textures/ocean.png");
	var->south = mlx_load_png("./textures/desert.png");
	var->east = mlx_load_png("./textures/forrest.png");
	var->west = mlx_load_png("./textures/sky.png");
	if (check_texture(var->north) || check_texture(var->south) || check_texture(var->east) || check_texture(var->west))
	{
		exit(0);
	}
}
