/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:43:25 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:43:26 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "wonderland.h"

typedef enum e_move
{
	front,
	left,
	back,
	right,
}	t_move;

void	get_hooks(t_world *world);

int		keys_press(int button, t_world *world);
int		keys_release(int button, t_world *world);

void	move_player(t_world *world, t_player *player);
void	front_back(t_world *world, t_move move);
void	left_right(t_world *world, t_move move);

void	rotate_player(t_world *world, t_player *player);

#endif