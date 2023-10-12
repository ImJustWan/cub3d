#include "wonderland.h"

int	clean_init(t_world *world)
{
	world->mlx = NULL;
	world->win = NULL;
	world->map = NULL;
	world->time = 0;
	world->old_time = 0;
	world->img.mlx_img = NULL;
	world->img.addr = NULL;
	world->img.bpp = 0;
	world->img.line_len = 0;
	world->img.endian = 0;
	world->pos_x = 4;
	world->pos_y = 3;
	world->player_x = (int)(world->pos_x + 0.5);
	world->player_y = (int)(world->pos_y + 0.5);
	world->ray.cos = 0;
	world->ray.sin = 0;
	world->ray.limit = 8;
	world->ray.orientation = 0; // depending on N(0)/ S(90)/ E(180)/ W(270);
	world->ray.half_cam_field = 30;
	return (0);
}
