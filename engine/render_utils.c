/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:42:07 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/14 18:42:21 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_top_bottom_pixel(t_var *var)
{
	var->wall_top_pixel = (HEIGHT / 2) - (var->wall_stripe_height / 2);
	if (var->wall_top_pixel < 0)
		var->wall_top_pixel = 0;
	var->wall_bottom_pixel = (HEIGHT / 2) + (var->wall_stripe_height / 2);
	if (var->wall_bottom_pixel > HEIGHT)
		var->wall_bottom_pixel = HEIGHT;
}
