/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:42:36 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 11:00:27 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_dir	get_dir(t_complex dir)
{
	if (fabs(dir.x) < 0.5)
	{
		if (dir.y < 0)
			return (a_up);
		else
			return (a_down);
	}
	else
	{
		if (dir.x < 0)
			return (a_left);
		else
			return (a_right);
	}
}

void	print_arrow(t_dir	dir)
{
	if (dir == a_up)
		ft_putstr_fd("\e[48;5;140m\e[30m↑\e[49m\e[0m", 1);
	else if (dir == a_down)
		ft_putstr_fd("\e[48;5;140m\e[30m↓\e[49m\e[0m", 1);
	else if (dir == a_left)
		ft_putstr_fd("\e[48;5;140m\e[30m←\e[49m\e[0m", 1);
	else
		ft_putstr_fd("\e[48;5;140m\e[30m→\e[49m\e[0m", 1);
}

void	draw_minimap(t_world *world, t_arrow arrow, int pos_x, int pos_y)
{
	int				i;
	int				j;

	i = -1;
	while (world->map[++i])
	{
		j = -1;
		write(1, "[", 1);
		while (world->map[i][++j])
		{
			if (j == pos_x && i == pos_y)
				print_arrow(arrow.dir);
			else if (world->map[i][j] == '1')
				write(1, "*", 1);
			else
				write(1, " ", 1);
		}
		write(1, "]\n", 2);
	}
	i = -1;
	while (world->map[++i])
		write(1, "\033[F", 3);
}

int	minimap(t_world *world)
{
	int				pos_x;
	int				pos_y;
	static t_arrow	arrow;

	if (!arrow.old_pos_x && !arrow.old_pos_y)
	{
		arrow.old_pos_x = (int)world->player->pos.x;
		arrow.old_pos_y = (int)world->player->pos.y;
		arrow.dir = get_dir(world->player->dir);
	}
	pos_x = (int)world->player->pos.x;
	pos_y = (int)world->player->pos.y;
	if ((pos_x == arrow.old_pos_x && pos_y == arrow.old_pos_y \
		&& arrow.dir == get_dir(world->player->dir)))
		return (0);
	arrow.old_pos_x = (int)world->player->pos.x;
	arrow.old_pos_y = (int)world->player->pos.y;
	arrow.dir = get_dir(world->player->dir);
	draw_minimap(world, arrow, pos_x, pos_y);
	return (0);
}
