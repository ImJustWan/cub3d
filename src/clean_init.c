#include "wonderland.h"

int	clean_init(t_world *world)
{
	world->mlx = NULL;
	world->win = NULL;
	world->time = 0;
	world->old_time = 0;
	world->img.mlx_img = NULL;
	world->img.addr = NULL;
	world->img.bpp = 0;
	world->img.line_len = 0;
	world->img.endian = 0;
	world->pos.x = 0;
	world->pos.y = 0;
	world->dir.x = 0;
	world->dir.y = 0;
	world->cam_field.x = 0;
	world->cam_field.y = 0;
	return (0);
}
