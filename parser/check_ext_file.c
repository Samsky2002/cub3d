/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:45:09 by asekkak           #+#    #+#             */
/*   Updated: 2023/10/14 12:39:12 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'c' 
			&& str[i + 2] == 'u'
			&& str[i + 3] == 'b' && str[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}
