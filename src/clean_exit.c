#include "wonderland.h"

int	clean_exit(t_world *world)
{
	if (!world)
		exit (0);
	if (world->img.mlx_img)
		mlx_destroy_image(world->mlx, world->img.mlx_img);
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
