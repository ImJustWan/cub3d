/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:43:21 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:43:22 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "wonderland.h"

int		loop(t_world *world);

int		display_init(t_world *world);

int		init_mlx(t_world *world);
int		init_setup(t_world *world, t_setup *setup);
int		init_raycast(t_world *world, t_raycast *ray);
int		init_player(t_world *world, t_player *player);
int		init_textures(t_world *world);

int		display(t_world *world);
int		display_raycast(t_world *world);
void	display_background(t_world *world);

int		get_color(t_world *world, int x, int y, int i);
void	img_pix_put(t_img *img, int x, int y, int color);

void	start_raycast(t_world *world, t_raycast *ray, int x);
void	step_dir_side_dist(t_player *player, t_raycast *ray);
void	wall_dist_and_side(t_raycast *ray, char **map);
void	index_height(t_world *world, t_raycast *ray);
void	start_end(t_world *world, t_raycast *ray);

#endif
