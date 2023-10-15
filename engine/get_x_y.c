/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:59:57 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 18:12:41 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_x(t_var *var)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = var->parser.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == var->parser.player)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_y(t_var *var)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = var->parser.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == var->parser.player)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}
