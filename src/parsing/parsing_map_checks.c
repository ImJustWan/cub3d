/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:38:34 by mrony             #+#    #+#             */
/*   Updated: 2023/10/26 15:06:29 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_surroundings(char **map, int i, int j)
{
	if (i == 0 || j == 0 || i == ft_table_size(map)
		|| j == (int)ft_strlen(map[i]))
		return (FAIL);
	if (!map[i - 1] || !map[i - 1][j] || !(ft_strchr("10NSEW", map[i - 1][j])))
		return (FAIL);
	if (!map[i + 1] || !map[i + 1][j] || !(ft_strchr("10NSEW", map[i + 1][j])))
		return (FAIL);
	if (!map[i][j - 1] || !(ft_strchr("10NSEW", map[i][j - 1])))
		return (FAIL);
	if (!map[i][j + 1] || !(ft_strchr("10NSEW", map[i][j + 1])))
		return (FAIL);
	return (SUCCESS);
}

void	set_player_dir(t_world *world)
{
	if (world->setup->orientation == NORTH)
	{
		world->setup->dir.y = -1;
		world->player->cam_plane.x = 0.66;
		world->player->cam_plane.y = 0.00;
	}
	if (world->setup->orientation == SOUTH)
	{
		world->setup->dir.y = 1;
		world->player->cam_plane.x = -0.66;
		world->player->cam_plane.y = 0.00;
	}
	if (world->setup->orientation == EAST)
	{
		world->setup->dir.x = -1;
		world->player->cam_plane.x = 0.00;
		world->player->cam_plane.y = -0.66;
	}
	if (world->setup->orientation == WEST)
	{
		world->setup->dir.x = 1;
		world->player->cam_plane.x = 0;
		world->player->cam_plane.y = 0.66;
	}
}

int	player_info(t_world *world, char **map, int i, int j)
{
	if (world->setup->pos.x != 0 || world->setup->pos.y != 0)
		return (FAIL);
	world->setup->pos.x = j;
	world->setup->pos.y = i;
	if (map[i][j] == 'N')
		world->setup->orientation = NORTH;
	else if (map[i][j] == 'S')
		world->setup->orientation = SOUTH;
	else if (map[i][j] == 'E')
		world->setup->orientation = EAST;
	else if (map[i][j] == 'W')
		world->setup->orientation = WEST;
	set_player_dir(world);
	map[i][j] = '0';
	return (SUCCESS);
}

int	comb_map(char **map, int i, int j)
{
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("10NSWE ", map[i][j]) == NULL)
				return (ft_error_msg(ERR, NULL, IMP, UKN), FAIL);
			j++;
		}
	}
	return (SUCCESS);
}

int	map_verif(t_world *world, char **map, int i, int j)
{
	if (comb_map(map, i, j))
		return (FAIL);
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ' )
				j++;
			else if (ft_strchr("0NSWE", map[i][j]) != NULL)
			{
				if (map[i][j] != '0' && player_info(world, map, i, j))
					return (ft_error_msg(ERR, NULL, IMP, MPL), FAIL);
				if (!check_surroundings(map, i, j))
					j++;
				else
					return (ft_error_msg(ERR, NULL, IMP, WAL), FAIL);
			}
			else
				return (FAIL);
		}
	}
	return (SUCCESS);
}
