#include "wonderland.h"
#include "parsing.h"

void	free_tab_tex(t_world *world)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (world->tab_tex[i].texture)
			free(world->tab_tex[i].texture);
}

void	free_setup(t_setup *setup)
{
	if (setup->no)
		free(setup->no);
	if (setup->so)
		free(setup->so);
	if (setup->ea)
		free(setup->ea);
	if (setup->we)
		free(setup->we);
	free(setup);
}

int	clean_exit(t_world *world)
{
	if (!world)
		exit (0);
	if (world->ray)
		free(world->ray);
	if (world->map)
		ft_free(world->map);
	if (world->setup)
		free_setup(world->setup);
	if (world->player)
		free(world->player);
	if (world->mlx_ptr)
	{
		if (world)
			free_tab_tex(world);
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
	if (world->minimap)
		free(world->minimap);
	exit (0);
}
