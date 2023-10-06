/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:35 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/06 19:43:47 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_var(t_var *var, char *file)
{
	var->mlx = mlx_init(WIDTH, HEIGHT, "42 balls", true);
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	var->rotation_angle = 3 * M_PI / 2;
	var->texture = NULL;
	var->texture = mlx_load_png("s_o_p.png");
	if (!var->texture)
	{
		printf("no image\n");
		exit(0);
	}
	var->lst = put_map(file);
	var->player_x = (TWOD_SIZE * get_x(var->lst)) - TWOD_SIZE + (TWOD_SIZE / 2);
	var->player_y = (TWOD_SIZE * get_y(var->lst)) - TWOD_SIZE + (TWOD_SIZE / 2);
	var->ray = malloc(sizeof(t_ray) * WIDTH);
	var->map_width = (ft_strlen(var->lst->content) - 1) * TWOD_SIZE;
	var->map_height = ft_lstsize(var->lst) * TWOD_SIZE;
	draw_map(var->lst, var->img);
	draw_player(var->lst, var->img, var);
}

void	init(t_var *var)
{
	cast_all_rays(var);
}

#include <stdint.h>


uint32_t rgba_to_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    return ((uint32_t)red << 24) | ((uint32_t)green << 16) | ((uint32_t)blue << 8) | alpha;
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
	init_var(&var, argv[1]);
	//var.list = malloc(sizeof(uint32_t) * var.texture->width * var.texture->height);
	/*for (int i = 0; i < var.texture->width * var.texture->height; i++) {

		uint8_t red = var.texture->pixels[i * 4];
    	uint8_t green = var.texture->pixels[i * 4 + 1];
    	uint8_t blue = var.texture->pixels[i * 4 + 2];
    	uint8_t alpha = var.texture->pixels[i * 4 + 3];
    	uint32_t color = rgba_to_color(red, green, blue, alpha);
		var.list[i] = color;
	}*/
	/*while (i < var.texture->width * var.texture->height)
	{
		mlx_put_pixel(var.img, (int)i % var.texture->width, (int)i / var.texture->width, var.list[i]);
		i++;
	}*/
	//init(&var);
	mlx_loop_hook(var.mlx, my_keyhook, &var);
	mlx_loop(var.mlx);
	mlx_terminate(var.mlx);
}

