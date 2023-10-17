#include "display.h"

int	loop(t_world *world)
{
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	display_background(world);
	mlx_loop(world->mlx_ptr);
	return (0);
}
