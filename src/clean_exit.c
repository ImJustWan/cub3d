#include "wonderland.h"

void	ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{	
		if (split[i])
			free(split[i]);
	}
	free(split);
	split = NULL;
}

int	clean_exit(t_world *world)
{
	if (!world)
		exit (0);
	if (world->img.mlx_img)
		mlx_destroy_image(world->mlx, world->img.mlx_img);
	if (world->map)
		free(world->map);
	if (world->mlx)
	{
		if (world->win)
			mlx_destroy_window(world->mlx, world->win);
		mlx_loop_end(world->mlx);
		mlx_destroy_display(world->mlx);
		free(world->mlx);
	}
	exit (0);
}
