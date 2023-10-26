#include "display.h"
#include "hooks.h"

int	loop(t_world *world)
{
	if (display_init(world))
		return (1);
	display_raycast(world);
	get_hooks(world);
	mlx_loop_hook(world->mlx_ptr, display, world);
	mlx_loop(world->mlx_ptr);
	return (0);
}

	// world->player->rotate = 0;
	// mlx_mouse_move(world->mlx_ptr, world->win, WIDTH / 2, HEIGHT / 2);