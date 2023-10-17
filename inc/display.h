#ifndef DISPLAY_H
# define DISPLAY_H

# include "wonderland.h"

void	image_init(t_world *world);
void	window_init(t_world *world);
void	start(t_world *world);
int		loop(t_world *world);
void	display_background(t_world *world);

int		ft_encode_rgb(int red, int green, int blue);

#endif
