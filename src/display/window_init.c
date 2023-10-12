/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:34:44 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/12 16:03:15 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "hooks.h"

void	window_init(t_world *world)
{
	world->win = mlx_new_window(world->mlx, WIDTH, HEIGHT, "Wonderlaaand");
	if (!world->win)
		clean_exit(world);
	mlx_loop_hook(world->mlx, loop, world);
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	mlx_key_hook(world->win, handle_keys, world);
	mlx_mouse_hook(world->win, handle_mouse, world);
	mlx_loop(world->mlx);
	mlx_destroy_image(world->mlx, world->img.mlx_img);
}
