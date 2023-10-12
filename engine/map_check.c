/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:02:06 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/12 11:06:27 by oakerkao         ###   ########.fr       */
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
	printf("x = %d\n", index_x);
	printf("y = %d\n", index_y);
	if (index_y >= 0 && index_y < var->map_height / SIZE && index_x >= 0 && index_x < var->map_width / SIZE &&  arr[index_y][index_x] == '1')	
		return (1);
	return (0);
}
