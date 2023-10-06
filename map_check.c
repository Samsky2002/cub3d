/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:02:06 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/06 11:58:13 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_player_on_wall(t_var *var, double x, double y) 
{
	int	index_x;
	int	index_y;
	char	**arr;

	index_x = floor(x / TWOD_SIZE);
	index_y = floor(y / TWOD_SIZE);
	arr = put_twod_array(var->lst);
	if (arr[index_y][index_x] == '1')	
		return (1);
	return (0);
}
