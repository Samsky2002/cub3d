/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:46:20 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 12:39:12 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part_check_color_and_floor_digit(int i, t_parser *parser)
{
	if (i < 0 || i > 255)
	{
		part_error();
	}
}

void	check_color_and_floor_digit(t_parser *parser)
{
	part_check_color_and_floor_digit(parser->ccolor.c1, parser);
	part_check_color_and_floor_digit(parser->ccolor.c2, parser);
	part_check_color_and_floor_digit(parser->ccolor.c3, parser);
	part_check_color_and_floor_digit(parser->fcolor.f1, parser);
	part_check_color_and_floor_digit(parser->fcolor.f2, parser);
	part_check_color_and_floor_digit(parser->fcolor.f3, parser);
}

int	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' ')
			return (0);
		i++;
	}
	return (0);
}

void	part_to_check_char(char *str)
{
	int		k;
	char	**mp;

	k = 0;
	mp = ft_split(str, ' ');
	while (mp[k])
	{
		if (mp[k][0] == '\n')
			break ;
		k++;
	}
	if (k > 1)
		part_error();
	k = 0;
	while (mp[k])
	{
		free(mp[k]);
		k++;
	}
	free(mp);
}

void	check_another_chara(char *str)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	part_to_check_char(str);
	while (str[k])
	{
		if (!((str[k] <= '9' && str[k] >= '0')
				|| str[k] == ' ' || str[k] == ',' 
				|| str[k] == '\n'))
			part_error();
		k++;
	}
}
