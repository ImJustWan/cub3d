#include "display.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->buff + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	image_to_window(t_world *world, int **buffer)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
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
			buffer[y][x] = world->setup->ceiling;
			buffer[HEIGHT - y - 1][x] = world->setup->floor;
		}
	}
	image_to_window(world, buffer);
}
