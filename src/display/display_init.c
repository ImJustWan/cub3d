#include "display.h"
#include "hooks.h"

int	init_player(t_world *world, t_player *player)
{
	player->pos.x = world->setup->pos.x;
	player->pos.y = world->setup->pos.y;
	player->dir.x = world->setup->dir.x;
	player->dir.y = world->setup->dir.y;
	world->player->rotate = 0;
	player->move.x = 0;
	player->move.y = 0;
	return (0);
}

int	init_raycast(t_world *world, t_raycast *ray)
{
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
	ray->cur_pos_x = world->setup->pos.x;
	ray->cur_pos_y = world->setup->pos.y;
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

	(void)world;
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

// void	fake_init(t_world *world)
// {
// 	world->player->pos.x = 1.5;
// 	world->player->pos.y = 1.5;
// 	world->from_scratch = 0;
// 	world->setup->orientation = NORTH;
// 	if (world->setup->orientation == NORTH)
// 	{
// 		world->player->dir.x = 0;
// 		world->player->dir.y = -1;
// 		world->player->cam_plane.x = 0.66;
// 		world->player->cam_plane.y = 0.00;
// 	}
// 	if (world->setup->orientation == SOUTH)
// 	{
// 		world->player->dir.x = 1;
// 		world->player->dir.y = 0;
// 		world->player->cam_plane.x = 0.00;
// 		world->player->cam_plane.y = 0.66;
// 	}
// 	if (world->setup->orientation == EAST)
// 	{
// 		world->player->dir.x = -1;
// 		world->player->dir.y = 0;
// 		world->player->cam_plane.x = 0.00;
// 		world->player->cam_plane.y = -0.66;
// 	}
// 	if (world->setup->orientation == WEST)
// 	{
// 		world->player->dir.x = 0;
// 		world->player->dir.y = 0;
// 		world->player->cam_plane.x = 0;
// 		world->player->cam_plane.y = 0.66;
// 	}
// }

void	display_init(t_world *world)
{
	init_mlx(world);
	init_raycast(world, world->ray);
	init_setup(world, world->setup);
	init_player(world, world->player);
	init_textures(world, world->texture);
	// fake_init(world);
}
