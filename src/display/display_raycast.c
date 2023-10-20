#include "display.h"
#include "hooks.h"

/*
- x goes from 0 to WIDTH
	- each iteration matches a column 1/WIDTH 
	- cam_x goes from -1 (furthest left) to 1 (furthest right) propotionnally to x
- cam_plane.x is 0 at start
- N / S
	- ray->ray_dir.x goes from [cam_plane.x] to -[cam_plane.x] 
	- ray->ray_dir.y stays at [cam_plane.y]
- E / W
	- ray->ray_dir.x stays at [cam_plane.x]
	- ray->ray_dir.y goes from -[cam_plane.y] to -[cam_plane.y] 
- cur_pos_x / cur_pos_y is the position of the player 
	at the start, and then after every move
- delta_dist is the hypotenuse of the triangle formed by the ray
	- x = distance traveled by the ray between two x sides
	- y = distance traveled by the ray between two y sides
		(pythagore)
		deltaX = sqrt(1 + (ray_dir.y * ray_dir.y) / (ray_dir.x * ray_dir.x))
		deltaY = sqrt(1 + (ray_dir.x * ray_dir.x) / (ray_dir.y * ray_dir.y))
			simplified to
				deltaX = abs(1 / ray_dir.x)
				deltaY = abs(1 / ray_dir.y)
- if ray->ray_dir.x or ray->ray_dir.y = 0 
	deltaX / deltaY set to INT_MAX to avoid division by 0
- N / S
	- deltaX goes from 1 to INT_MAX to 1
	- deltaY = 1 
- E / W
	- deltaX = 1 
	- deltaY goes from 1 to INT_MAX to 1

*/

void	start_raycast(t_world *world, t_raycast *ray, int x)
{
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = world->player->dir.x + \
		world->player->cam_plane.x * ray->cam_x;
	ray->ray_dir.y = world->player->dir.y + \
		world->player->cam_plane.y * ray->cam_x;
	ray->cur_pos_x = (int)world->player->pos.x;
	ray->cur_pos_y = (int)world->player->pos.y;
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = INT_MAX;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = INT_MAX;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

void	step_dir_side_dist(t_player *player, t_raycast *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (player->pos.x - ray->cur_pos_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = ray->delta_dist.x * \
			(ray->cur_pos_x + 1.0 - player->pos.x);
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (player->pos.y - ray->cur_pos_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = ray->delta_dist.y * \
			(ray->cur_pos_y + 1.0 - player->pos.y);
	}
}
void	wall_dist_and_side(t_raycast *ray, char **map)
{
	int	wall;

	wall = 0;
	while (wall != 1)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->cur_pos_x += ray->step_dir.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->cur_pos_y += ray->step_dir.y;
			ray->side = 1;
		}
		// if (ray->cur_pos_x < 0.25 || ray->cur_pos_y < 0.25 \
		// 	|| ray->cur_pos_x > (int)ft_strlen(map[ray->cur_pos_x]) \
		// 	|| (map[ray->cur_pos_x][ray->cur_pos_y] == '1'))
		if (map[ray->cur_pos_y][ray->cur_pos_x] == '1')
			wall = 1;
	}
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
}

void	index_height_start_end(t_world *world, t_raycast *ray)
{
	(void)world;
	ray->wall_height = (int)(HEIGHT / ray->wall_dist);
	if (ray->side == 1)
	{
		if (ray->ray_dir.y < 0)
			ray->index_texture = SOUTH;
		else
			ray->index_texture = NORTH;
	}
	else
	{
		if (ray->ray_dir.x < 0)
			ray->index_texture = EAST;
		else
			ray->index_texture = WEST;
	}
	if (ray->side == 0)
		ray->wall_pos = world->player->pos.y + \
			(ray->wall_dist * ray->ray_dir.y);
	else
		ray->wall_pos = world->player->pos.x + \
			(ray->wall_dist * ray->ray_dir.x);
	ray->wall_pos -= floor(ray->wall_pos);
	ray->x_on_tex = (int)(ray->wall_pos * (double)TEXTURE_WIDTH);
	if ((ray->side == 0 && ray->ray_dir.x > 0)
		|| (ray->side == 1 && ray->ray_dir.y < 0))
		ray->x_on_tex = TEXTURE_WIDTH - ray->x_on_tex - 1;
	ray->draw_start = (HEIGHT / 2) - (ray->wall_height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (HEIGHT / 2) + (ray->wall_height) / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

/*
ray_height = tex_pos
wall_height = line_height
*/

void	the_actual_raycasting(t_world *world, t_raycast *ray, int x)
{
	int	y;
	int	color;

	ray->step = 1.0 * TEXTURE_WIDTH / ray->wall_height;
	ray->ray_height = ray->step * \
		(ray->draw_start - HEIGHT / 2 + ray->wall_height / 2);
	y = -1;
	// printf("x [%d] y [%d]\n", x, y);
	while (++y < ray->draw_start)
	{
		// printf("segfault x [%d] y [%d]\n", x, y);
		world->buffer[y][x] = world->setup->f;
	}
	while (y < ray->draw_end)
	{
		ray->y_on_tex = (int)ray->ray_height & (TEXTURE_HEIGHT - 1);
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

// ray_height (ex depth) = tex_pos 

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
		index_height_start_end(world, world->ray);
		the_actual_raycasting(world, world->ray, x);
	}
	raycast_to_window(world);
}

int	display_raycast(t_world *world)
{
	move_player(world, world->player);
	rotate_player(world, world->player);
	printf("player->pos[%f][%f]\n", world->player->pos.x, world->player->pos.y);
	// printf("DIRECTION [%d]\n", world->setup->orientation);
	big_loop(world);
	return (0);
}
