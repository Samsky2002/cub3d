/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:57:09 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 12:39:12 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rep_path(t_parser *parser)
{
	if (parser->count_no != 1 || parser->count_so != 1
		|| parser->count_ea != 1 || parser->count_we != 1)
		part_error();
}

char	*take_path(t_parser *parser, char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	parser->count++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		part_error();
	while (str[i])
	{
		res = char_join(res, str[i]);
		i++;
	}
	return (res);
}

void	line_by_line(char *file, t_parser *parser)
{
	char	*str;
	int		fd;

	parser->file = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0);
	str = get_next_line(fd);
	while (str)
	{
		ft_lstadd_back(&parser->file, ft_lstnew(str));
		str = get_next_line(fd);
	}
	check_file_line(parser);
	check_tab(parser);
}
