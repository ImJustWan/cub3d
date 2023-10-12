#include "wonderland.h"
#include "display.h"
#include "error.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_world	world;

	(void)argc;
	(void)argv;
	if (argc != 2)
		return(ft_error_msg(ERR, &argc, ARG, USG), 1);
	clean_init(&world);
	if (parsing(&world, argv))
		clean_exit(&world);
	world.mlx = mlx_init();
	if (!world.mlx)
		return (1);
	window_init(&world);

	clean_exit(&world);
	return (1);
}
