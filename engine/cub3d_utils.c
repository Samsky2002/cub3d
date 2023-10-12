/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakerkao <oakerkao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:55:35 by oakerkao          #+#    #+#             */
/*   Updated: 2023/10/12 12:45:48 by oakerkao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_twod_size(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

char	**put_twod_array(t_list *lst)
{
	int		len;
	char	**arr;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	len = put_twod_size(tmp);
	arr = malloc((len + 1) * sizeof(char *));
	while (tmp)
	{
		//arr[i] = ft_strtrim(tmp->content, "\n");
		arr[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	*char_join(char *str, char c)
{
	char	*result;
	int		len;
	int		i;
	char	*help;

	i = 0;
	if (!str)
	{
		result = malloc(2);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	len = ft_strlen(str);
	result = malloc(len + 2);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}