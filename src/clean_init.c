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

int	clean_init_textures(t_world *world)
{
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

int	clean_init(t_world *world)
{
	clean_init_struct(world);
	clean_init_textures(world);
	world->mlx_ptr = NULL;
	world->win = NULL;
	world->time = 0;
	world->old_time = 0;
	world->map = NULL;
	world->setup->c = -1;
	world->setup->f = -1;
	world->setup->pos.x = 0;
	world->setup->pos.y = 0;
	return (0);
}
