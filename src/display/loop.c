#include "display.h"
#include "hooks.h"

int	loop(t_world *world)
{
	int	i;

	i = -1;
	while (world->map[++i])
		printf("map[%d] is [%s]\n", i, world->map[i]);
	display_init(world);
	get_hooks(world);
	display_raycast(world);
	mlx_loop_hook(world->mlx_ptr, display_raycast, world);
	world->player->rotate = 0;
	mlx_mouse_move(world->mlx_ptr, world->win, WIDTH / 2, HEIGHT / 2);
	mlx_loop(world->mlx_ptr);
	return (0);
}
