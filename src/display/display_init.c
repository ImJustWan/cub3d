/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:42:43 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:42:44 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "hooks.h"

int	init_player(t_world *world, t_player *player)
{
	player->pos.x = world->setup->pos.x + 0.5;
	player->pos.y = world->setup->pos.y + 0.5;
	player->dir.x = world->setup->dir.x;
	player->dir.y = world->setup->dir.y;
	world->player->rotate = 0;
	player->move.x = 0;
	player->move.y = 0;
	return (0);
}

int	init_raycast(t_world *world, t_raycast *ray)
{
	(void)world;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->cam_x = 0;
	ray->side = 0;
	ray->wall_pos = 0;
	ray->wall_dist = 0;
	ray->cam_plane.x = 0;
	ray->cam_plane.y = 0;
	ray->ray_dir.x = 0;
	ray->ray_dir.y = 0;
	ray->cur_pos_x = 0;
	ray->cur_pos_y = 0;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = 0;
	ray->delta_dist.y = 0;
	ray->step_dir.x = 0;
	ray->step_dir.y = 0;
	ray->xpm.x = 0;
	ray->xpm.y = 0;
	ray->index_texture = 0;
	ray->wall_height = 0;
	ray->ray_height = 0;
	return (0);
}

int	init_setup(t_world *world, t_setup *setup)
{
	int	i;
	int	j;

	setup->orientation = -1;
	if (world->from_scratch == 1)
	{
		i = -1;
		while (++i < HEIGHT)
		{
			j = -1;
			while (++j < WIDTH)
				world->buffer[i][j] = 0;
		}
		i = -1;
		while (++i < MINI_HEIGHT)
		{
			j = -1;
			while (++j < MINI_WIDTH)
				world->mini_buff[i][j] = 0;
		}
	}
	return (0);
}

int	init_mlx(t_world *world)
{
	world->mlx_ptr = mlx_init();
	if (!world->mlx_ptr)
		return (1);
	world->win = mlx_new_window(world->mlx_ptr, WIDTH, HEIGHT, "Wonderlaaand");
	if (!world->win)
		return (1);
	world->img->img_ptr = mlx_new_image(world->mlx_ptr, WIDTH, HEIGHT);
	if (!world->img->img_ptr)
		return (1);
	world->img->addr = (int *)mlx_get_data_addr(world->img->img_ptr, \
		&(world->img->bpp), &(world->img->line_len), &(world->img->endian));
	if (!world->img->addr)
		return (1);
	return (0);
}

int	display_init(t_world *world)
{
	init_mlx(world);
	init_raycast(world, world->ray);
	init_setup(world, world->setup);
	init_player(world, world->player);
	if (init_textures(world))
		return (1);
	return (0);
}
