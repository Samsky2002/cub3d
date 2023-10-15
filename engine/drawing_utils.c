/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:58:05 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 18:51:43 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	draw_map(t_list *lst, mlx_image_t *img, t_var *var)
{
	char	*str;
	int		i;
	int		j;
	int		a;
	int		b;
	t_list	*tmp;
	char	**arr;

	i = 0;
	tmp = lst;
	arr = var->parser.map;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			a = i * SIZE;
			while (a < (SIZE * i) + SIZE)
			{
				b = j * SIZE;
				while (b < (SIZE * j) + SIZE)
				{
					if (arr[i][j] == '1')
						mlx_put_pixel(img, b, a, 0xFFFFFF);
					else if (arr[i][j] == '0' || arr[i][j] == 'N')
						mlx_put_pixel(img, b, a, 0x000000);
					b++;
				}
				a++;
			}
			j++;
		}
		lst = lst->next;
		i++;
	}
}

void	draw_player(t_list *lst, mlx_image_t *img, t_var *var)
{
	int	i;
	int	j;

	i = var->player_x;
	j = var->player_y;
	mlx_put_pixel(img, i, j, 0xFFFFFF);
}*/

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	clear_map(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(var->img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
