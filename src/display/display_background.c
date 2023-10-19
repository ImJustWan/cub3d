#include "display.h"

void	background_to_window(t_world *world, int **buffer)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		y++;
		x = -1;
		while (++x < WIDTH)
			img_pix_put(world->img, x, y, buffer[y][x]);
	}
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->img->img_ptr, 0, 0);
	y = 0;
	while (y < HEIGHT)
	{
		free(buffer[y]);
		y++;
	}
	free(buffer);
}

void	display_background(t_world *world)
{
	int	x;
	int	y;
	int	**buffer;

	buffer = (int **)ft_calloc(sizeof(int *), HEIGHT);
	y = -1;
	while (++y < HEIGHT)
		buffer[y] = (int *)malloc(sizeof(int) * WIDTH);
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
		{
			buffer[y][x] = world->setup->c;
			buffer[HEIGHT - y - 1][x] = world->setup->f;
		}
	}
	background_to_window(world, buffer);
}
