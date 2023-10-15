/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:02:06 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 19:56:26 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player_on_wall(t_var *var, double x, double y)
{
	int	index_x;
	int	index_y;

	index_x = floor(x / SIZE);
	index_y = floor(y / SIZE);
	if (!(index_y >= 0 && index_y < var->map_height / SIZE))
		return (1);
	if (!(index_x >= 0 && index_x < (int)ft_strlen(var->parser.map[index_y])))
		return (1);
	if (var->parser.map[index_y][index_x] == '1') 
		return (1);
	return (0);
}
