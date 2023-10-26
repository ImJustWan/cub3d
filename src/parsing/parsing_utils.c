/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:38:52 by mrony             #+#    #+#             */
/*   Updated: 2023/10/26 10:38:54 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	map_size(t_list *map_lst)
{
	int	size;

	size = 0;
	while (map_lst)
	{
		if (empty_line((char *)map_lst->content) == FALSE)
			size++;
		else
			break ;
		map_lst = map_lst->next;
	}
	return (size);
}

int	ft_table_size(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return (0);
	while (table[i])
		i++;
	return (i);
}

void	free_split(char **split)
{
	if (split && split[0])
		free(split[0]);
	free(split);
}
