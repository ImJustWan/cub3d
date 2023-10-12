#ifndef ERROR_H
# define ERROR_H

# include "wonderland.h"

# define ERR "\1\033[1m\2\1\033[38;5;127m\2Error\n\1\033[0m\2"

# define ARG "Incorrect number of arguments"
# define USG "\1\033[38;5;118m\2\
Usage: ./cub3d [scene_description_file.cub]\
\1\033[0m\2"

# define CUB "Incorect file extension."

void	ft_error_msg(char *err, int *ptr, char *arg, char *str);

#endif