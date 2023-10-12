/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:34:44 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/12 15:54:28 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "hooks.h"

void	window_init(t_world *world)
{
	void	*img;
	char	*path = "./xpm/wonderland_wall_north.xpm";
	int		img_width;
	int		img_height;
	
	world->win = mlx_new_window(world->mlx, WIDTH, HEIGHT, "Wonderlaaand");
	if (!world->win)
		clean_exit(world);
	mlx_loop_hook(world->mlx, hook_loop, world);
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	mlx_key_hook(world->win, handle_keys, world);
	mlx_mouse_hook(world->win, handle_mouse, world);
	img = mlx_xpm_file_to_image(world->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(world->mlx, world->win, img, 10, 20);
	mlx_loop(world->mlx);
	mlx_destroy_image(world->mlx, world->img.mlx_img);
}
