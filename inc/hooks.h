#ifndef HOOKS_H
# define HOOKS_H

#include "wonderland.h"

int	hook_loop(int button, int x, int y, t_world *world);
int	handle_keys(int button, int x, int y, t_world *world);
int	handle_mouse(int button, int x, int y, t_world *world);

#endif