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

int	    keys_press(int button, t_world *world);
int	    keys_release(int button, t_world *world);
int	    handle_mouse(int button, int x, int y, t_world *world);

void	move_player(t_world *world);

#endif