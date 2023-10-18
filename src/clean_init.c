#include "wonderland.h"

int	clean_init(t_world *world)
{
	int	i;
	int	j;

	world->mlx_ptr = NULL;
	world->win = NULL;
	world->time = 0;
	world->from_scratch = 0;
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
	(*world).texture = (int **)malloc(sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		(*world).texture[i] = (int *)malloc(sizeof(int) * \
			TEXTURE_HEIGHT * TEXTURE_WIDTH);
		j = -1;
		while (++j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
			(*world).texture[i][j] = 0;
	}
	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			world->buffer[i][j] = 0;
	}
	return (0);
}

/*
world->ray.orientation
depends on N(0)/ S(90)/ E(180)/ W(270);
*/