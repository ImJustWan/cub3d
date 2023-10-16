#include "wonderland.h"
#include "parsing.h"

// void	ft_empty_hat(t_hat *hat)
// {
// 	t_hat *next;

// 	while (hat)
// 	{
// 		if (hat->index)
// 			free(hat->index);
// 		if (hat->path)
// 			free(hat->path);
// 		if (hat->rgb)
// 			free(hat->rgb);
// 		next = hat->next;
// 		free(hat);
// 		hat = next;
// 	}
// 	if (hat)
// 		free(hat);
// 	hat = NULL;
// }

int	clean_exit(t_world *world)
{
	if (!world)
		exit (0);
	if (world->ray)
		free(world->ray);
	if (world->map)
		ft_free(world->map);
	if (world->setup)
		free(world->setup);
	if (world->player)
		free(world->player);
	if (world->mlx_ptr)
	{
		if (world->img->img_ptr)
			mlx_destroy_image(world->mlx_ptr, world->img->img_ptr);
		if (world->win)
			mlx_destroy_window(world->mlx_ptr, world->win);
		mlx_loop_end(world->mlx_ptr);
		mlx_destroy_display(world->mlx_ptr);
		free(world->mlx_ptr);
	}
	if (world->img)
		free(world->img);
	exit (0);
}
