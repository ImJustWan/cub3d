#include "wonderland.h"

void	clear_textures(t_world *world)
{
	int	i;

	i = -1;
	while (++i < 4)
		free((*world).texture[i]);
	free(world->texture);
	free(world->setup->no);
	free(world->setup->so);
	free(world->setup->ea);
	free(world->setup->we);
}

void	ft_free(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
		split[i] = NULL;
	}
	free(split);
}

int	clean_exit(t_world *world)
{
	if (!world)
		exit (0);
	clear_textures(world);
	if (world->map)
		ft_free(world->map);
	if (world->ray)
		free(world->ray);
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
