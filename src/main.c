#include "wonderland.h"
#include "display.h"

int	main(int argc, char **argv)
{
	t_world	world;

	(void)argc;
	(void)argv;

	clean_init(&world);
	start(&world);
	clean_exit(&world);
	return (1);
}
