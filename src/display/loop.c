#include "display.h"

int	loop(t_world *world)
{
	display_init(world);
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	// display_background(world);
	display_raycast(world, world->ray);
	// mlx_put_image_to_window(world, world->win, world->img->img_ptr, 0, 0);
	mlx_loop(world->mlx_ptr);
	return (0);
}
/*

funnsies

	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[0].img_ptr, (WIDTH / 2) - (world->texture[0].width / 2), 100);
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[1].img_ptr, (WIDTH / 2) - (world->texture[1].width / 2), 275);
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[2].img_ptr, (WIDTH / 2) - (world->texture[2].width / 2), 450);
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[3].img_ptr, (WIDTH / 2) - (world->texture[3].width / 2), 625);


*/
