/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:02:54 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/06 11:45:46 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*put_map(char *file)
{
	char	*line;
	int		fd;
	t_list	*lst;

	lst = NULL;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		ft_lstadd_back(&lst, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (lst);
}
