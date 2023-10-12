/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:35 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/12 12:14:08 by oakerkao         ###   ########.fr       */
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
	//len = ft_strlen(map[i])
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

void	init_var(t_var *var, char *file)
{
	var->mlx = mlx_init(WIDTH, HEIGHT, "42 balls", true);
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	var->rotation_angle = 3 * M_PI / 2;
	var->lst = put_map(file);
	var->map = put_twod_array(var->lst);
	var->player_x = (SIZE * get_x(var->lst)) - (SIZE / 2);
	var->player_y = (SIZE * get_y(var->lst)) - (SIZE / 2);
	var->ray = malloc(sizeof(t_ray) * WIDTH);
//	var->map_width = (ft_strlen(var->lst->content) - 1) * SIZE;
	var->map_height = ft_lstsize(var->lst) * SIZE;
	var->map_width = /*get_map_width(var->map)*/ 47 * SIZE;
	var->fov = 60 * (M_PI / 180);
}

int main(int argc, char *argv[])
{
	int		fd;
	t_var	var;
	t_list	*tmp;

	if (argc != 2)
	{
		printf("where is the map dummy\n");
		exit(0);
	}
	parser(argv[1]);
	exit(0);
	get_textures(&var);
	init_var(&var, argv[1]);
	mlx_loop_hook(var.mlx, my_keyhook, &var);
	mlx_loop(var.mlx);
	mlx_terminate(var.mlx);
}

