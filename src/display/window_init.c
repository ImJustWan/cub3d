#include "display.h"
#include "hooks.h"

void	window_init(t_world *world)
{
	world->win = mlx_new_window(world->mlx_ptr, WIDTH, HEIGHT, "Wonderlaaand");
	if (!world->win)
		clean_exit(world);
	mlx_loop_hook(world->mlx_ptr, loop, world);
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	mlx_key_hook(world->win, handle_keys, world);
	mlx_mouse_hook(world->win, handle_mouse, world);
	mlx_loop(world->mlx_ptr);
	world->img->img_ptr = mlx_new_image(world->mlx_ptr, WIDTH, HEIGHT);
	world->img->buff = (unsigned int *)mlx_get_data_addr(world->img->img_ptr, \
		&(world->img->bpp), &(world->img->line_len), &(world->img->endian));
}
