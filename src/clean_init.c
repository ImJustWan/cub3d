#include "wonderland.h"

int	clean_init(t_world *world)
{
	world->mlx_ptr = NULL;
	world->win = NULL;
	world->time = 0;
	world->old_time = 0;
	world->map = NULL;
	world->img = ft_calloc(1, sizeof(t_img));
	if (!world->img)
		return (1);
	world->ray = ft_calloc(1, sizeof(t_raycast));
	if (!world->ray)
		return (1);
	world->setup = ft_calloc(1, sizeof(t_setup));
	if (!world->setup)
		return (1);
	world->player = ft_calloc(1, sizeof(t_player));
	if (!world->player)
		return (1);
	return (0);
}

/*
world->ray.orientation
depends on N(0)/ S(90)/ E(180)/ W(270);
*/