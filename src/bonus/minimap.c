/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:12:50 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/25 17:39:38 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	minimap_to_window(t_world *world)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MINI_HEIGHT)
	{
		x = -1;
		while (++x < MINI_WIDTH)
		{
			// printf("color shoul be [%d]\n", world->mini_buff[y][x]);
			world->minimap->addr[MINI_WIDTH * y + x] = world->mini_buff[y][x];
		}
	}
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->minimap->img_ptr, WIDTH - MINI_WIDTH, HEIGHT - MINI_HEIGHT);
}

void	put_mini_pixel(t_world *world, int x, int y, int color)
{
	int		i;
	int		j;
	// int		*dst;

	i = y;
	(void)color;
	(void)world;
	while (i < MINI_HEIGHT)
	{
		j = x;
		while (j < MINI_WIDTH)
		{
			// printf("pixel[%d][%d] will be color\n", i, j);
			world->mini_buff[i][j] = color;
			j++;
		}
		i++;
	}
}

int	draw_miniplayer(t_world *world)
{
	(void)world;
	return (0);
}

int	draw_minimap(t_world *world)
{
	int	x;
	int	y;
	int	mini_x;
	int	mini_y;

	y = -1;
	while (world->map[++y])
	{
		x = -1;
		while (world->map[y][++x])
		{
			mini_y = y * 15;
			mini_x = x * 15;
			if (world->map[y][x] == '1')
				put_mini_pixel(world, mini_x, mini_y, COOL_GRAY);
		}
	}
	minimap_to_window(world);
	return (0);
}

int	minimap(t_world *world)
{
	world->minimap->img_ptr = mlx_new_image \
		(world->mlx_ptr, MINI_WIDTH, MINI_HEIGHT);
	if (!world->minimap->img_ptr)
		return (1);
	world->minimap->addr = (int *)mlx_get_data_addr \
		(world->minimap->img_ptr, &(world->minimap->bpp), \
			&(world->minimap->line_len), &(world->minimap->endian));
	if (!world->minimap->addr)
		return (1);
	// printf("curent_player_pos[%f][%f]\n", world->player->pos.y, world->player->pos.x);
	mlx_destroy_image(world->mlx_ptr, world->minimap->img_ptr);
	// draw_minimap(world);
	return (0);
}
