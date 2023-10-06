/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:44:09 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/01 13:03:46 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*new_ray(double wall_hit_x, double wall_hit_y, double distance)
{
	t_ray	*new;

	new = malloc(sizeof(t_ray));
	new->wall_hit_x = wall_hit_x;
	new->wall_hit_y = wall_hit_y;
	new->distance = distance;
	new->next = NULL;
	return (new);
}

void	add_ray(t_ray **ray, t_ray *new)
{
	t_ray	*head;

	if (!*ray)
	{
		*ray = new;
		return ;
	}
	head = *ray;
	while (head->next)
		head = head->next;
	head->next = new;
}
