#include "wonderland.h"

int	clean_init_struct(t_world *world)
{
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

int	clean_init_buffer(t_world *world)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			world->buffer[i][j] = 0;
	}
	return (0);
}

int	clean_init(t_world *world)
{
	if (clean_init_struct(world))
		return (1);
	clean_init_buffer(world);
	world->mlx_ptr = NULL;
	world->win = NULL;
	world->time = 0;
	world->from_scratch = 0;
	world->old_time = 0;
	world->map = NULL;
	world->setup->c = -1;
	world->setup->f = -1;
	world->setup->pos.x = 0;
	world->setup->pos.y = 0;
	return (0);
}

/*
world->ray.orientation
depends on N(0)/ S(90)/ E(180)/ W(270);
*/