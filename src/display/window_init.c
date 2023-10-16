/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:34:44 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/16 11:28:57 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "hooks.h"

void	window_init(t_world *world)
{
	world->win = mlx_new_window(world->mlx_ptr, WIDTH, HEIGHT, "Wonderlaaand");
	if (!world->win)
		clean_exit(world);
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	mlx_loop(world->mlx_ptr);
	world->img->img_ptr = mlx_new_image(world->mlx_ptr, WIDTH, HEIGHT);
	world->img->buff = mlx_get_data_addr(world->img->img_ptr, \
		&(world->img->bpp), &(world->img->line_len), &(world->img->endian));
}
