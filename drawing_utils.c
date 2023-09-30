/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:58:05 by oakerkao          #+#    #+#             */
/*   Updated: 2023/09/30 13:28:32 by oakerkao         ###   ########.fr       */
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
			a = i * SIZE;
			while (a < (SIZE * i) + SIZE)
			{
				b = j * SIZE;
				while (b < (SIZE * j) + SIZE)
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
	int	a;
	int	b;

	i = var->player_x;
	j = var->player_y;
	a = 10 + j;
	b = 10 + i;
	/*while (j < a)
	{
		i = var->player_x;
		while (i < b)
		{
			mlx_put_pixel(img, i, j, 0xFFFFFF);
			i++;
		}
		j++;
	}*/
	mlx_put_pixel(img, i, j, 0xFFFFFF);
}
