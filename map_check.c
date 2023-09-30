/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:02:06 by oakerkao          #+#    #+#             */
/*   Updated: 2023/09/29 12:03:09 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_player_on_wall(t_var *var, double x, double y) 
{
	int	index_x;
	int	index_y;
	char	**arr;

	index_x = floor(x / SIZE);
	index_y = floor(y / SIZE);
	arr = put_twod_array(var->lst);
	if (arr[index_y][index_x] == '1')	
		return (1);
	return (0);
}
