/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:49:53 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 20:01:24 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_struct(t_parser *parser, char *str, int j)
{
	if (j == 0)
		parser->fcolor.f1 = ft_atoi(str);
	else if (j == 1)
		parser->fcolor.f2 = ft_atoi(str);
	else if (j == 2)
		parser->fcolor.f3 = ft_atoi(str);
}

void	cieling_struct(t_parser *parser, char *str, int j)
{
	if (j == 0)
		parser->ccolor.c1 = ft_atoi(str);
	else if (j == 1)
		parser->ccolor.c2 = ft_atoi(str);
	else if (j == 2)
		parser->ccolor.c3 = ft_atoi(str);
}

void	char_to_int(t_parser *parser, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!(str[i] <= '9' && str[i] >= '0'))
		part_error();
	if (c == 'f')
		floor_struct(parser, str + i, j);
	if (c == 'c')
		cieling_struct(parser, str + i, j);
}

void	take_string_color(t_parser *parser, char *str, char c)
{
	int		i;
	int		j;
	char	**colors;

	i = 0;
	j = 0;
	colors = ft_split(str, ',');
	while (colors[i])
	{
		check_another_chara(colors[i]);
		char_to_int(parser, colors[i], c, i);
		i++;
	}
	while (colors[j])
	{
		free(colors[j]);
		j++;
	}
	free(colors);
}

void	take_color(t_parser *parser, char *str, char c)
{
	int	i;

	i = 0;
	parser->count++;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		part_error();
	else
		take_string_color(parser, str + i, c);
}
