#ifndef DISPLAY_H
# define DISPLAY_H

# include "wonderland.h"

int		loop(t_world *world);

void	display_init(t_world *world);

int		init_mlx(t_world *world);
int		init_setup(t_world *world, t_setup *setup);
int     init_raycast(t_world *world, t_raycast *ray);
int		init_player(t_world *world, t_player *player);
int		init_textures(t_world *world, int **texture);

void	display_background(t_world *world);
int 	display_raycast(t_world *world);

int 	get_color(t_world *world, int x, int y, int i);
void	img_pix_put(t_img *img, int x, int y, int color);

#endif
