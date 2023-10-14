/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cara_without_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:43:10 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 12:39:12 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part_of_check_char(t_parser *parser, char *str, int i)
{
	if (str[i] == 'F' && str[i + 1] == ' ')
		take_color(parser, str + 1, 'f');
	else if (str[i] == 'C' && str[i + 1] == ' ')
		take_color(parser, str + 1, 'c');
	else if (parser->count != 6)
		part_error();
}

void	check_char(char *str, t_parser *parser)
{
	int	i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
	{
		parser->no = take_path(parser, str + 2);
		parser->count_no++;
	}
	else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
	{
		parser->so = take_path(parser, str + 2);
		parser->count_so++;
	}
	else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
	{
		parser->ea = take_path(parser, str + 2);
		parser->count_ea++;
	}
	else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
	{
		parser->we = take_path(parser, str + 2);
		parser->count_we++;
	}
	else
		part_of_check_char(parser, str, i);
}
