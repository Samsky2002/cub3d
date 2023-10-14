/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:55:25 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 12:39:12 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_cub(t_parser *parser, int i)
{
	int	j;

	j = 0;
	if (i == 0)
		printf("Error");
	if (parser->no)
		free(parser->no);
	if (parser->so)
		free(parser->so);
	if (parser->we)
		free(parser->we);
	if (parser->ea)
		free(parser->ea);
	if (parser->file)
		ft_lstclear(&parser->file, free);
	if (parser->map)
	{
		while (parser->map[j])
		{
			free(parser->map[j]);
			j++;
		}
		free(parser->map);
	}
	exit(0);
}

void	part_error(void)
{
	
	printf("Error\n");
	exit(0);
}
