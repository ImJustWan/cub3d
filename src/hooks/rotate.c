/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:43:07 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:43:08 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	rotate_player(t_world *world, t_player *player)
{
	double	rotspeed;
	double	tmp;

	rotspeed = ROT_SPEED * world->player->rotate;
	tmp = player->dir.x;
	player->dir.x = player->dir.x * cos(rotspeed) \
		- player->dir.y * sin(rotspeed);
	player->dir.y = tmp * sin(rotspeed) \
		+ player->dir.y * cos(rotspeed);
	tmp = player->cam_plane.x;
	player->cam_plane.x = player->cam_plane.x * cos(rotspeed) \
		- player->cam_plane.y * sin(rotspeed);
	player->cam_plane.y = tmp * sin(rotspeed) \
		+ player->cam_plane.y * cos(rotspeed);
}
