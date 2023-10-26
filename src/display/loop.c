/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:42:56 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:42:57 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "hooks.h"

int	loop(t_world *world)
{
	if (display_init(world))
		return (1);
	display_raycast(world);
	get_hooks(world);
	mlx_loop_hook(world->mlx_ptr, display, world);
	mlx_loop(world->mlx_ptr);
	return (0);
}

	// world->player->rotate = 0;
	// mlx_mouse_move(world->mlx_ptr, world->win, WIDTH / 2, HEIGHT / 2);