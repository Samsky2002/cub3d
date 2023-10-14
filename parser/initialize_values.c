/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:56:43 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 12:39:12 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	part_of_initial(t_parser *parser)
{
	parser->ea = NULL;
	parser->we = NULL;
	parser->no = NULL;
	parser->so = NULL;
	parser->list = NULL;
	parser->ccolor.c1 = 0;
	parser->ccolor.c2 = 0;
	parser->ccolor.c3 = 0;
	parser->fcolor.f1 = 0;
	parser->fcolor.f2 = 0;
	parser->fcolor.f3 = 0;
}

void	initialize_value(t_parser *parser)
{
	parser->error = 1;
	parser->len_map = 0;
	parser->count_player = 0;
	parser->count = 0;
	parser->count_we = 0;
	parser->count_no = 0;
	parser->count_so = 0;
	parser->count_ea = 0;
	parser->incr = 0;
	part_of_initial(parser);
}
