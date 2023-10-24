#include "hooks.h"
#include "display.h"

void	the_actual_raycasting(t_world *world, t_raycast *ray, int x)
{
	int	y;
	int	color;

	ray->step = 1.0 * TEXTURE_HEIGHT / ray->wall_height;
	ray->ray_height = ((double)ray->draw_start - \
		((double)HEIGHT / 2) + (ray->wall_height / 2)) * ray->step;
	y = -1;
	while (++y < ray->draw_start)
		world->buffer[y][x] = world->setup->f;
	while (y < ray->draw_end)
	{
		ray->y_on_tex = (int)ray->ray_height % TEXTURE_HEIGHT;
		ray->ray_height += ray->step;
		color = world->texture[ray->index_texture] \
			[TEXTURE_HEIGHT * ray->y_on_tex + ray->x_on_tex];
		world->buffer[y][x] = color;
		world->from_scratch = 1;
		y++;
	}
	while (++y < HEIGHT)
		world->buffer[y][x] = world->setup->c;
}

void	raycast_to_window(t_world *world)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			world->img->addr[WIDTH * y + x] = world->buffer[y][x];
	}
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->img->img_ptr, 0, 0);
}

void	big_loop(t_world *world)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		start_raycast(world, world->ray, x);
		step_dir_side_dist(world->player, world->ray);
		wall_dist_and_side(world->ray, world->map);
		index_height(world, world->ray);
		start_end(world, world->ray);
		the_actual_raycasting(world, world->ray, x);
	}
	raycast_to_window(world);
}

int	display_raycast(t_world *world)
{
	move_player(world, world->player);
	rotate_player(world, world->player);
	big_loop(world);
	return (0);
}
