#include "wonderland.h"

int	img_init(t_world *world)
{
	world->img->img_ptr = NULL;
	world->img->buff = NULL;
	world->img->bpp = 0;
	world->img->line_len = 0;
	world->img->endian = 0;
	return (0);
}

int	clean_init(t_world *world)
{
	world->mlx_ptr = NULL;
	world->win = NULL;
	world->img = NULL;
	world->time = 0;
	world->old_time = 0;
	world->pos.x = 4;
	world->pos.y = 3;
	world->player.x = (int)(world->pos.x + 0.5);
	world->player.y = (int)(world->pos.y + 0.5);
	world->ray.cos = 0;
	world->ray.sin = 0;
	world->ray.limit = 8;
	world->ray.orientation = 0;
	world->ray.half_cam_field = 30;
	return (0);
}

/*
world->ray.orientation
depends on N(0)/ S(90)/ E(180)/ W(270);
*/