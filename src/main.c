#include "wonderland.h"
#include "display.h"

void	default_map(t_world *world)
{
	world->map = ft_calloc(6, sizeof(char *));
	world->map[0] = "111111";
	world->map[1] = "100101";
	world->map[2] = "100101";
	world->map[3] = "1100N1";
	world->map[4] = "111111";
	world->map[5] = "\0";
}

int	main(int argc, char **argv)
{
	t_world	world;

	(void)argc;
	(void)argv;
	clean_init(&world);
	world.mlx = mlx_init();
	if (!world.mlx)
		return (1);
	default_map(&world);
	window_init(&world);
	clean_exit(&world);
	return (1);
}
