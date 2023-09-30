/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:35 by oakerkao          #+#    #+#             */
/*   Updated: 2023/09/30 16:46:29 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(void *param)
{
	t_var	*var;

	var = param;
	draw_map(var->lst, var->img);
	draw_player(var->lst, var->img, var);
//	DDA(var, var->player_x, var->player_y, var->player_x + cos(var->rotation_angle) * 25, var->player_y + sin(var->rotation_angle) * 25);
	cast_all_rays(var);
}

int main(int argc, char *argv[])
{
	int		fd;
	t_var	var;

	if (argc != 2)
	{
		printf("where is the map dummy\n");
		exit(0);
	}
	var.mlx = mlx_init(WIDTH, HEIGHT, "42 balls", true);
	var.img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	fd = open(argv[1], O_RDONLY);
	var.lst = put_map(fd);
	var.player_x = (SIZE * get_x(var.lst)) - SIZE + (SIZE / 2);
	var.player_y = (SIZE * get_y(var.lst)) - SIZE + (SIZE / 2);
	var.rotation_angle = 3 * M_PI / 2;
	var.angle = var.rotation_angle - (FOV/ 2);
	mlx_loop_hook(var.mlx, init, &var);
	mlx_loop_hook(var.mlx, my_keyhook, &var);
	mlx_image_to_window(var.mlx, var.img, 0, 0);
	mlx_loop(var.mlx);
	mlx_terminate(var.mlx);
}
