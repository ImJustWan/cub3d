/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:42:02 by mrony             #+#    #+#             */
/*   Updated: 2023/11/03 14:46:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	clean_mlx(t_world *world)
{
	if (world)
		free_tab_tex(world);
	if (world->img->img_ptr)
		mlx_destroy_image(world->mlx_ptr, world->img->img_ptr);
	if (world->win)
		mlx_destroy_window(world->mlx_ptr, world->win);
	mlx_loop_end(world->mlx_ptr);
	if (world->mlx_ptr != NULL)
		mlx_destroy_display(world->mlx_ptr);
	free(world->mlx_ptr);
}

int	clean_exit(t_world *world, int ex)
{
	if (!world)
		exit (0);
	if (world->ray)
		free(world->ray);
	if (world->map)
		ft_free(world->map);
	if (world->setup)
		free_setup(world->setup);
	if (world->player)wall_pos
		free(world->player);
	if (world->mlx_ptr)
		clean_mlx(world);
	if (world->img)
		free(world->img);
	if (world->minimap)
		free(world->minimap);
	printf("\e[?25h");
	exit (ex);
}
