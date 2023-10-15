/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:16:44 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 19:59:14 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	take_player(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (parser->map[i])
	{
		j = 0;
		while (parser->map[i][j])
		{
			if (parser->map[i][j] == 'N' || parser->map[i][j] == 'S' || \
					parser->map[i][j] == 'W' || parser->map[i][j] == 'E')
				parser->player = parser->map[i][j];
			j++;
		}
		i++;
	}
}

int	checked_file(char *ac)
{
	int	fd;

	fd = open(ac, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

int	textures(char *file)
{
	if (checked_file(file) == 0)
		return (0);
	return (1);
}

t_parser	parts_parser(char *file)
{
	t_parser	parser;

	initialize_value(&parser);
	textures(file);
	line_by_line(file, &parser);
	map(&parser);
	take_player(&parser);
	return (parser);
}

void	parser(char *file, t_var *var)
{
	t_parser	p;

	if (check_extension(file) == 1)
	{
		printf("Error");
		exit(0);
	}
	if (check_file(file) == 0)
	{
		printf("Error");
		exit(0);
	}
	p = parts_parser(file);
	var->parser = p;
}
