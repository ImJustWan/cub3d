#ifndef PARSING_H
# define PARSING_H

# include "wonderland.h"
# include "error.h"

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

// parsing.c
int	parsing(t_world *world, char **argv);

// hat_list_functions.c
t_hat	*ft_hatnew(char *index, char *path);
void	ft_add_back_hat(t_hat **hat, t_hat *new);
t_hat	*ft_hatlast(t_hat *node);
int	ft_hat_size(t_hat *node);

#endif