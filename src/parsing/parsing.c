#include "parsing.h"

// void	print_info(t_world *world)
// {
// 	int	i;

// 	i = 0;
// 	printf("\1\033[1m\2\1\033[38;5;127m\2Parsed map:\1\033[0m\2\n");
// 	while (world->map[i])
// 	{
// 		printf("[%s]\n", world->map[i]);
// 		i++;
// 	}
// 	printf("\n\1\033[1m\2\1\033[38;5;127m\2\
// Parsed player info:\1\033[0m\2\n");
// 	printf("Player position: x=[%f], y=[%f]\n",
// 		world->setup->pos.x, world->setup->pos.y);
// 	printf("Player direction: x=[%f], y=[%f]\n",
// 		world->setup->dir.x, world->setup->dir.y);
// 	printf("\n\1\033[1m\2\1\033[38;5;127m\2\
// Parsed colors:\1\033[0m\2\n");
// 	printf("Ceiling color: [%d]\n", world->setup->c);
// 	printf("Floor color: [%d]\n", world->setup->f);
// 	printf("\n\1\033[1m\2\1\033[38;5;127m\2\
// Parsed colors:\1\033[0m\2\n");
// 	printf("North texture: [%s]\n", world->setup->no);
// 	printf("South texture: [%s]\n", world->setup->so);
// 	printf("East texture: [%s]\n", world->setup->ea);
// 	printf("West texture: [%s]\n", world->setup->we);
// }

int	parsing(t_world *world, char **argv)
{
	t_list	*read;

	read = NULL;
	if (file_name(argv) || read_file(argv, &read) || !read)
	{
		if (read)
			ft_clear(read);
		clean_exit(world);
	}
	if (parsing_map(world, read))
		return (ft_clear(read), FAIL);
	if (parsing_description(world, read))
		return (FAIL);
	return (SUCCESS);
}

	// print_info(world);