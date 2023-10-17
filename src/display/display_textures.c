#include "display.h"

int	get_texture(t_world *world, t_texture *texture, int i)
{
	char	*file;

	file = NULL;
	if (i == NORTH)
		file = world->setup->no;
	if (i == SOUTH)
		file = world->setup->so;
	if (i == EAST)
		file = world->setup->ea;
	if (i == WEST)
		file = world->setup->we;
	world->texture[i].img_ptr = mlx_xpm_file_to_image(world->mlx_ptr, \
		"x_north.xpm", &(texture[i].width), &(texture[i].height));
	if (!world->texture[i].img_ptr)
		return (1);
	world->texture[i].addr = mlx_get_data_addr(texture[i].img_ptr, \
		&(texture[i].bpp), &(texture[i].line_len), &(texture[i].endian));
	if (!world->texture[i].addr)
		return (1);
	return (0);
}

int	init_textures(t_world *world, t_texture *texture)
{
	int	i;

	i = -1;
	while (++i < 4)
		get_texture(world, texture, i);
	return (0);
}
