/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:35 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/15 09:58:39 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_width(char **map)
{
	int	prev;
	int	current;
	int	len;
	int	i;

	prev = 0;
	current = 0;
	i = 0;
	while (map[i])
	{
		current = ft_strlen(map[i]);
		if (current > prev)
			len = current;
		prev = current;
		i++;
	}
	return (len);
}

void	get_rotation_angle(t_var *var)
{
	if (var->parser.player == 'N')
		var->rotation_angle = 3 * M_PI / 2;
	else if (var->parser.player == 'S')
		var->rotation_angle = M_PI / 2;
	else if (var->parser.player == 'E')
		var->rotation_angle = 0;
	else if (var->parser.player == 'W')
		var->rotation_angle = M_PI;
}

int	twod_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	init_var(t_var *var)
{
	var->mlx = mlx_init(WIDTH, HEIGHT, "42 balls", true);
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	get_rotation_angle(var);
	var->player_x = (SIZE * get_x(var)) + (SIZE / 2);
	var->player_y = (SIZE * get_y(var)) + (SIZE / 2);
	var->ray = malloc(sizeof(t_ray) * WIDTH);
	var->map_height = twod_size(var->parser.map) * SIZE;
	// fix the width
	var->map_width = 1000 * SIZE;
	mlx_image_to_window(var->mlx, var->img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_var	var;

	if (argc != 2)
	{
		exit(0);
	}
	parser(argv[1], &var);
	get_textures(&var);
	init_var(&var);
	mlx_loop_hook(var.mlx, my_keyhook, &var);
	mlx_loop(var.mlx);
	//cleaning(&var);
	mlx_terminate(var.mlx);
}

void	free_twod_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	cleaning(t_var *var)
{
	ft_lstclear(&var->parser.file, free);
	ft_lstclear(&var->parser.list, free);
	free_twod_array(var->parser.map);
	free(var->parser.no);
	free(var->parser.so);
	free(var->parser.we);
	free(var->parser.ea);
	free(var->ray);
	mlx_delete_texture(var->north);
	mlx_delete_texture(var->south);
	mlx_delete_texture(var->east);
	mlx_delete_texture(var->west);
	mlx_delete_image(var->mlx, var->img);
}

// Deletes an image and removes it from the render queue.
//void mlx_delete_image(mlx* mlx, mlx_image_t* image)
/*
 * linked list
 * file list
 * double arr map
 * no
 * so
 * we
 * ea
 * ray struct
 * textures
 * image
 * 
 */
