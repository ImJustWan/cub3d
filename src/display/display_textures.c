#include "display.h"

int	fill_texture_info(t_world *world, t_img *img, int i)
{
	int	y;

	world->tab_tex[i].texture = (int *)ft_calloc(sizeof(int), \
			img->width * img->height);
	if (!world->tab_tex[i].texture)
		return (1);
	y = -1;
	while (++y < img->width * img->height)
		world->tab_tex[i].texture[y] = 0;
	world->tab_tex[i].width = img->width;
	world->tab_tex[i].height = img->height;
	return (0);
}

int	load_texture(t_world *world, t_img *img, char *path, int i)
{
	int	x;
	int	y;
	int	color;

	img->img_ptr = mlx_xpm_file_to_image(world->mlx_ptr,
			path, &img->width, &img->height);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->line_len, &img->endian);
	if (fill_texture_info(world, img, i))
		return (1);
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			color = img->addr[img->width * y + x];
			world->tab_tex[i].texture[img->width * y + x] = color;
		}
	}
	return (0);
}

int	get_texture(t_world *world, int i)
{
	int		res;
	char	*file;
	t_img	img;

	file = NULL;
	res = 0;
	if (i == NORTH)
		res = load_texture(world, &img, world->setup->no, i);
	if (i == SOUTH)
		res = load_texture(world, &img, world->setup->so, i);
	if (i == EAST)
		res = load_texture(world, &img, world->setup->ea, i);
	if (i == WEST)
		res = load_texture(world, &img, world->setup->we, i);
	mlx_destroy_image(world->mlx_ptr, img.img_ptr);
	return (res);
}

int	init_textures(t_world *world)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (get_texture(world, i))
			return (1);
	return (0);
}
