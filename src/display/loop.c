#include "display.h"

void	image_to_window(t_world *world,int **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			world->img->buff[i * WIDTH + j] = buffer[i][j];
			printf("pixel n [%d] color is [%d]\n", i * WIDTH + j, buffer[i][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(world->mlx_ptr, world->win, world->img->img_ptr, WIDTH, HEIGHT);
	printf("image put to window\n");
}

void	background(t_world *world)
{
	int	i;
	int	j;
	int	**buff;
	int	c;
	int	f;

	c = world->setup->ceiling;
	f = world->setup->floor;
	printf("c is [%d] and f is [%d]\n", c, f);
	buff = (int **)ft_calloc(sizeof(int *), HEIGHT);
	i = 0;
	while (i < HEIGHT)
	{
		buff[i] = (int *)malloc(sizeof(int) * WIDTH);
		i++;
	}
	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			buff[i][j] = world->setup->ceiling;
			buff[HEIGHT - i - 1][j] = world->setup->floor;
			j++;
		}
		i++;
	}
	image_to_window(world, buff);
	i = 0;
	while (i < HEIGHT)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}

int	loop(t_world *world)
{
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	background(world);
	mlx_loop(world->mlx_ptr);
	return (0);
}
