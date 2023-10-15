/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:58:30 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 19:58:00 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_part_1(t_parser *parser, int i, int j)
{
	if (!((parser->map[i][j + 1] == '1' || parser->map[i][j + 1] == '0'
		|| parser->map[i][j + 1] == 'N' || parser->map[i][j + 1] == 'S'
			|| parser->map[i][j + 1] == 'E' || parser->map[i][j + 1] == 'W')
			&& (parser->map[i][j - 1] == '1' || parser->map[i][j - 1] == '0'
			|| parser->map[i][j - 1] == 'N' || parser->map[i][j - 1] == 'S'
			|| parser->map[i][j - 1] == 'E' || parser->map[i][j - 1] == 'W')
			&& (parser->map[i + 1][j] == '1' || parser->map[i + 1][j] == '0'
			|| parser->map[i + 1][j] == 'N' || parser->map[i + 1][j] == 'S'
			|| parser->map[i + 1][j] == 'E' || parser->map[i + 1][j] == 'W')
			&& (parser->map[i - 1][j] == '1' || parser->map[i - 1][j] == '0'
			|| parser->map[i - 1][j] == 'N' || parser->map[i - 1][j] == 'S'
			|| parser->map[i - 1][j] == 'E' || parser->map[i - 1][j] == 'W')))
		part_error();
}

void	check_map(t_parser *parser)
{
	int		i;
	int		j;

	i = 0;
	check_last_first_line(parser);
	while (parser->map[i])
	{
		j = 0;
		while (parser->map[i][j])
		{
			if (parser->map[i][j] == '0')
			{
				if (parser->map[i][0] == '0')
					part_error();
				check_map_part_1(parser, i, j);
			}
			j++;
		}
		if (!check_char_map(parser->map[i], parser))
			part_error();
		i++;
	}
}

void	check_map_if_empty_line(t_parser *parser)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	k = 0;
	while (parser->map[i])
	{
		j = 0;
		while (parser->map[i] && parser->map[i][j] == ' ')
			j++;
		if (parser->map[i][j] == '\n')
			part_error();
		i++;
	}
	check_map(parser);
	if (parser->count_player != 1)
		part_error();
}

void	store_map(t_parser *parser, int i)
{
	t_list	*lst;
	t_list	*tmp;
	int		j;

	lst = parser->file;
	j = 0;
	while (lst)
	{
		if (i <= j)
			ft_lstadd_back(&parser->list, ft_lstnew(lst->content));
		lst = lst->next;
		j++;
	}
	tmp = parser->list;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	if (ft_strchr(tmp->content, '\n'))
		part_error();
	parser->map = put_twod_array(parser->list);
	check_map_if_empty_line(parser);
	parser->len_map = ft_lstsize(parser->list) - 1;
}

void	map(t_parser *parser)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = parser->file;
	while (lst)
	{
		if (parser->incr < i)
		{
			if (!check_if_wall(lst->content))
			{
				store_map(parser, i);
				break ;
			}
		}
		lst = lst->next;
		i++;
	}
}
