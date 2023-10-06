/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:58:05 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/06 15:29:43 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_var *var)
{
	int	i;
	int	x;
	int	y;
	int	len;

	i = 0;
	len = 40;
	x = var->player_x;
	y = var->player_y;
	y--;
	while (i < len)
	{
		mlx_put_pixel(var->img, x, y, 0xFFFFFF);
		y--;
		i++;
	}
}

void	draw_map(t_list *lst, mlx_image_t *img)
{
	char	*str;
	int		i;
	int		j;
	int		a;
	int		b;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (i < ft_lstsize(tmp))
	{
		str = lst->content;
		j = 0;
		while (str[j])
		{
			a = i * TWOD_SIZE;
			while (a < (TWOD_SIZE * i) + TWOD_SIZE)
			{
				b = j * TWOD_SIZE;
				while (b < (TWOD_SIZE * j) + TWOD_SIZE)
				{
					if (str[j] == '1')
						mlx_put_pixel(img, b, a, 0xFFFFFF);
					else if (str[j] == '0' || str[j] == 'N')
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
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
