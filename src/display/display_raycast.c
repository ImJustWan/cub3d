#include "hooks.h"
#include "display.h"
#include "minimap.h"

/*
    the_actual_raycasting
    This final function is the one actually casting the ray 
    and placing the right texture stripe on our buffer (future image)
*/

void	the_actual_raycasting(t_world *world, t_raycast *ray, int x)
{
	int	y;
	int	color;

	ray->step = 1.0 * world->tab_tex[ray->index_texture].height / \
		ray->wall_height;
	ray->ray_height = ((double)ray->draw_start - \
		((double)HEIGHT / 2) + (ray->wall_height / 2)) * ray->step;
	y = -1;
	while (++y < ray->draw_start)
		world->buffer[y][x] = world->setup->f;
	while (y < ray->draw_end)
	{
		ray->y_on_tex = (int)ray->ray_height % \
			world->tab_tex[ray->index_texture].height;
		ray->ray_height += ray->step;
		color = world->tab_tex[ray->index_texture].texture \
			[(world->tab_tex[ray->index_texture].height) * \
				ray->y_on_tex + ray->x_on_tex];
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

/*
    Big_loop 
	Scans the screen width from left (x = -1) to right (x = WIDTH)
    and calls all the necessary functions to create an image.
    Once all of the pixels of an image are 
	computed and stored in the buffer, 
    the buffer content is copied to the image address
	before pushing the image to the window.
    
    1.    start ray_cast
    2.    step_dir_side_dist
    3.    wall_dist_and_side
    4.    index_height
    5.    start_end
    6.    the_actual_raycasting
 */

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

/* Display raycast calls 3 main function that
		will determin what we see on the screen.
    1.    The position of the player: move_player.
        Which is modified via the key hooks.
    2.    The player's orientation: rotate_player.
        Which is also midified via the key hooks.
    3.    The big_loop calculating each ray of the screen
		before pushing all the pixels to the screen.
*/

int	display_raycast(t_world *world)
{
	move_player(world, world->player);
	rotate_player(world, world->player);
	big_loop(world);
	minimap(world);
	return (0);
}

int	display(t_world *world)
{
	move_player(world, world->player);
	rotate_player(world, world->player);
	display_raycast(world);
	return (0);
}
