#include "wonderland.h"
#include "display.h"
#include "error.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_world	world;

	if (argc != 2)
		return (ft_error_msg(ERR, &argc, ARG, USG), 1);
	if (clean_init(&world))
		return (1);
	if (parsing(&world, argv))
		clean_exit(&world);
	if (loop(&world))
		clean_exit(&world);
	clean_exit(&world);
	return (1);
}
