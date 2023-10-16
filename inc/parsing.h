#ifndef PARSING_H
# define PARSING_H

# include "wonderland.h"
# include "error.h"

# define FAIL 1
# define SUCCESS 0

# define TRUE 1
# define FALSE 0



// typedef struct s_hat
// {
// 	char			*index;
// 	char			*path;
// 	int				*rgb;
// 	struct s_hat	*prev;
// 	struct s_hat	*next;
// }	t_hat;

// parsing.c
int	parsing(t_world *world, char **argv);

// parsing_read.c
int file_name(char **argv);
int	read_file(char **argv, t_list **read);

// parsing_map.c
int	check_map(t_world *world, t_list *read);

// // parsing_read.c
// int	check_description(t_world *world, t_list *read);

// // content.c
// // int	check_content(t_world *world, t_list **read);

// // utils.c
int	empty_line(char *str);
// int	file_access(char *path);

// hat_list_functions.c
// void	ft_add_back_hat(t_hat **hat, t_hat *new);
// int		ft_hat_size(t_hat *node);
// t_hat	*ft_hatnew(char *index, char *path, int *rgb);
// t_hat	*ft_hatlast(t_hat *node);

#endif