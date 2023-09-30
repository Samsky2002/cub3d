/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:59:57 by oakerkao          #+#    #+#             */
/*   Updated: 2023/09/29 12:00:23 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_x(t_list *lst)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		j = 0;
		str = lst->content;
		while (str[j])
		{
			if (str[j] == 'N')
				return (j + 1);
			j++;
		}
		i++;
		lst = lst->next;
	}
	return (0);
}

int	get_y(t_list *lst)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	len = ft_lstsize(lst);
	i = 0;
	while (i < len)
	{
		j = 0;
		str = lst->content;
		while (str[j])
		{
			if (str[j] == 'N')
				return (i + 1);
			j++;
		}
		i++;
		lst = lst->next;
	}
	return (0);
}
