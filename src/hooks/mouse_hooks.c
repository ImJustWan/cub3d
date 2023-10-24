#include "hooks.h"

int	handle_mouse(int x, int y, t_world *world)
{
	(void)y;
	world->player->rotate = (x - WIDTH / 2) / 100;
	return (0);
}
