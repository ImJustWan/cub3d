#ifndef PARSING_H
# define PARSING_H

# include "wonderland.h"

// typedef enum e_type
// {
// 	nort = 101,
// 	south,
// 	west,
// 	east,
// 	floor,
// 	ceiling,
// } t_type;

typedef struct s_hat
{
	char			*index;
	char			*path;
	int				rgb[3];
	struct s_hat	*prev;
	struct s_hat	*next;
}	t_hat;

#endif