#include "wonderland.h"

int	clean_exit(t_world *world)
{
	if (!world)
		exit (0);
	if (world->img && world->img->img_ptr)
		mlx_destroy_image(world->mlx_ptr, world->img->img_ptr);
	if (world->mlx_ptr)
	{
		if (world->win)
			mlx_destroy_window(world->mlx_ptr, world->win);
		mlx_loop_end(world->mlx_ptr);
		mlx_destroy_display(world->mlx_ptr);
		free(world->mlx_ptr);
	}
	exit (0);
}
