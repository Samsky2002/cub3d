/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:45:17 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 20:48:13 by oakerkao         ###   ########.fr       */
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
	char	*str;

	var->north = NULL;
	var->south = NULL;
	var->east = NULL;
	var->west = NULL;
	str = ft_strtrim(var->parser.no, "\n");
	var->north = mlx_load_png(str);
	free(str);
	str = ft_strtrim(var->parser.so, "\n");
	var->south = mlx_load_png(str);
	free(str);
	str = ft_strtrim(var->parser.ea, "\n");
	var->east = mlx_load_png(str);
	free(str);
	str = ft_strtrim(var->parser.we, "\n");
	var->west = mlx_load_png(str);
	free(str);
	if (check_texture(var->north) || check_texture(var->south) || \
			check_texture(var->east) || check_texture(var->west))
	{
		// parsing leaks
		//cleaning(var);
		exit(0);	
	}
}
