#include "display.h"

int	load_texture(t_world *world, t_img *img, char *path, int i)
{
	int	x;
	int	y;
	int	color;

	img->img_ptr = mlx_xpm_file_to_image(world->mlx_ptr, \
		path, &img->width, &img->height);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->line_len, &img->endian);
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			color = img->addr[img->width * y + x];
			world->texture[i][img->width * y + x] = color;
		}
	}
	return (0);
}

int	get_texture(t_world *world, int i)
{
	char	*file;
	t_img	img;

	file = NULL;
	if (i == NORTH)
		load_texture(world, &img, world->setup->no, i);
	if (i == SOUTH)
		load_texture(world, &img, world->setup->so, i);
	if (i == WEST)
		load_texture(world, &img, world->setup->ea, i);
	if (i == EAST)
		load_texture(world, &img, world->setup->we, i);
	mlx_destroy_image(world->mlx_ptr, img.img_ptr);
	return (0);
}

int	init_textures(t_world *world, int **texture)
{
	int		i;

	(void)texture;
	i = -1;
	while (++i < 4)
		get_texture(world, i);
	return (0);
}
