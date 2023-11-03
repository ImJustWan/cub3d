/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_des_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:38:30 by mrony             #+#    #+#             */
/*   Updated: 2023/11/03 13:27:17 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	store_no(t_world *world, char **split)
{
	if (!world->setup->no)
		world->setup->no = split[1];
	else
		return (ft_error_msg(ERR, NULL, IFL, DPX), FAIL);
	return (SUCCESS);
}

int	store_so(t_world *world, char **split)
{
	if (!world->setup->so)
		world->setup->so = split[1];
	else
		return (ft_error_msg(ERR, NULL, IFL, DPX), FAIL);
	return (SUCCESS);
}

int	store_ea(t_world *world, char **split)
{
	if (!world->setup->ea)
		world->setup->ea = split[1];
	else
		return (ft_error_msg(ERR, NULL, IFL, DPX), FAIL);
	return (SUCCESS);
}

int	store_we(t_world *world, char **split)
{
	if (!world->setup->we)
		world->setup->we = split[1];
	else
		return (ft_error_msg(ERR, NULL, IFL, DPX), FAIL);
	return (SUCCESS);
}

int	texture_save(t_world *world, char **split)
{
	int	fd;

	if (!ft_strstr(split[1], ".xpm\0"))
		return (ft_error_msg(ERR, NULL, IFL, XPM), FAIL);
	fd = open(split[1], O_RDONLY);
	if (fd == -1)
		return (ft_error_msg(ERR, NULL, IFL, NULL), FAIL);
	close(fd);
	if (!ft_strcmp(split[0], "NO\0"))
		return (store_no(world, split));
	else if (!ft_strcmp(split[0], "SO\0"))
		return (store_so(world, split));
	else if (!ft_strcmp(split[0], "EA\0"))
		return (store_ea(world, split));
	else if (!ft_strcmp(split[0], "WE\0"))
		return (store_we(world, split));
	else
		return (ft_error_msg(ERR, NULL, IFL, UKN), FAIL);
	return (SUCCESS);
}
