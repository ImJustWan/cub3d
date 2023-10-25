#include "hooks.h"

int	handle_mouse(int x, int y, t_world *world)
{
	(void)y;
	if (!BONUS)
		world->player->rotate = (x - WIDTH / 2) / 100;
	else
		world->player->rotate = (x - WIDTH / 2);
	mlx_mouse_move(world->mlx_ptr, world->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
