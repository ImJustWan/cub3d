/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:43:02 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:43:03 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "hooks.h"
#include "bonus.h"

int	keys_release(int button, t_world *world)
{
	if (button == LEFT && world->player->rotate <= 1)
		world->player->rotate = 0;
	if (button == RIGHT && world->player->rotate >= 1)
		world->player->rotate = 0;
	if (button == KEY_W && world->player->move.y == 1)
		world->player->move.y = 0;
	if (button == KEY_A && world->player->move.x == -1)
		world->player->move.x = 0;
	if (button == KEY_S && world->player->move.y == -1)
		world->player->move.y = 0;
	if (button == KEY_D && world->player->move.x == 1)
		world->player->move.x = 0;
	return (0);
}

int	keys_press(int button, t_world *world)
{
	if (button == LEFT)
		world->player->rotate -= 1;
	if (button == RIGHT)
		world->player->rotate += 1;
	if (button == KEY_W)
		world->player->move.y = 1;
	if (button == KEY_A)
		world->player->move.x = -1;
	if (button == KEY_S)
		world->player->move.y = -1;
	if (button == KEY_D)
		world->player->move.x = 1;
	if (button == ESC)
		clean_exit(world);
	return (0);
}

void	get_hooks(t_world *world)
{
	if (BONUS > 0)
		mlx_hook(world->win, MotionNotify, \
			PointerMotionMask, handle_mouse, world);
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	mlx_hook(world->win, KeyPress, KeyPressMask, keys_press, world);
	mlx_hook(world->win, KeyRelease, KeyReleaseMask, keys_release, world);
}
