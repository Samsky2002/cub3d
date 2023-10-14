/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_by_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:47:57 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 12:39:12 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line_char(char *str, t_parser *parser)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] == '\0' || str[i] == '\n')
			break ;
		else
		{
			check_char(str + i, parser);
			break ;
		}
		i++;
	}
	check_color_and_floor_digit(parser);
}

void	check_file_line(t_parser *parser)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = parser->file;
	while (lst)
	{
		check_line_char(lst->content, parser);
		lst = lst->next;
		i++;
		if (parser->count == 6)
			break ;
	}
	parser->incr = i;
	check_rep_path(parser);
}

void	check_last_first_line(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (parser->map[0][i])
	{
		if (!(parser->map[0][i] == '1' || parser->map[0][i] == ' '
				|| parser->map[0][i] == '\0' || parser->map[0][i] == '\n'))
			part_error();
		i++;
	}
	while (parser->map[j])
		j++;
	j--;
	i = 0;
	while (parser->map[j][i])
	{
		if (!(parser->map[j][i] == '1' || parser->map[j][i] == ' '
				|| parser->map[j][i] == '\0' || parser->map[j][i] == '\n'))
			part_error();
		i++;
	}
}

int	check_if_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != '\n' && str[i] != ' ')
			part_error();
		if (str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_char_map(char *str, t_parser *parser)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != ' ' && str[i] != '\n' 
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (0);
		if (str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W')
			parser->count_player++;
		i++;
	}
	return (1);
}
