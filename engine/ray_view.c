/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:02:54 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 13:58:55 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_view(t_var *var, double angle)
{
	var->up = 0;
	var->down = 0;
	var->left = 0;
	var->right = 0;
	if (angle > 0 && angle < M_PI)
		var->down = 1;
	else
		var->up = 1;
	if (angle < M_PI * 0.5 || angle > 1.5 * M_PI)
		var->right = 1;
	else
		var->left = 1;
}
