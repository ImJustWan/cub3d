/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_des.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:38:32 by mrony             #+#    #+#             */
/*   Updated: 2023/10/26 10:38:33 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	dispatch_info(t_world *world, char **split)
{
	int	split_size;

	split_size = ft_table_size(split);
	if (split_size < 2)
		return (ft_error_msg(ERR, NULL, IFL, MFP), FAIL);
	if (split_size > 2)
		return (ft_error_msg(ERR, NULL, IFL, MIF), FAIL);
	if (ft_strlen(split[0]) == 2)
	{
		if (texture_save(world, split))
			return (FAIL);
		return (free_split(split), SUCCESS);
	}
	else if (ft_strlen(split[0]) == 1)
	{
		if (color_save(world, split))
			return (FAIL);
		ft_free(split);
	}
	else
		return (ft_error_msg(ERR, NULL, IFL, IID), FAIL);
	return (SUCCESS);
}

int	save_info(t_world *world, char *str)
{
	char	**split;

	split = ft_split(str, 32);
	if (!split)
		return (ft_error_msg(ERR, NULL, PAR, MAL), FAIL);
	if (dispatch_info(world, split))
		return (ft_free(split), FAIL);
	return (SUCCESS);
}

int	parsing_description(t_world *world, t_list *read)
{
	t_list	*cpy;
	t_setup	*check;

	read = remove_empty_lines(read);
	remove_newline(read);
	cpy = read;
	while (cpy)
	{
		if (save_info(world, (char *)cpy->content))
			return (ft_clear(read), FAIL);
		cpy = cpy->next;
	}
	ft_clear(read);
	check = world->setup;
	if (!check->no || !check->so || !check->ea || !check->we)
		return (ft_error_msg(ERR, NULL, IDF, MTX), FAIL);
	if (check->f == -1 || check->c == -1)
		return (ft_error_msg(ERR, NULL, IDF, MSC), FAIL);
	return (SUCCESS);
}
