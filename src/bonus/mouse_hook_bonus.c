/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:42:38 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:42:39 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "bonus.h"

int	handle_mouse(int x, int y, t_world *world)
{
	(void)y;
	if (!BONUS)
		world->player->rotate = (x - WIDTH / 2) / 100;
	else
		world->player->rotate = (x - WIDTH / 2);
	mlx_mouse_move(world->mlx_ptr, world->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
