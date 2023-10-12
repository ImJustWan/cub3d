#include "wonderland.h"
#include "display.h"

int	main(int argc, char **argv)
{
	t_world	world;

	(void)argc;
	(void)argv;
	clean_init(&world);
	world.mlx_ptr = mlx_init();
	if (!world.mlx_ptr)
		return (1);
	window_init(&world);
	clean_exit(&world);
	return (1);
}
