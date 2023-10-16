#include "display.h"
#include "hooks.h"

int	init_player(t_world *world, t_player *player)
{
	player->pos.x = world->setup->pos.x;
	player->dir.x = world->setup->dir.x;
	player->pos.y = world->setup->pos.y;
	player->dir.y = world->setup->dir.y;
	return (0);
}

int	init_setup(t_world *world)
{
	world->setup->ceiling = ft_encode_rgb(102, 0, 102);
	world->setup->floor = ft_encode_rgb(255, 153, 51);
	return (0);
}

int	init_mlx(t_world *world)
{
	world->mlx_ptr = mlx_init();
	if (!world->mlx_ptr)
		return (1);
	world->win = mlx_new_window(world->mlx_ptr, WIDTH, HEIGHT, "Wonderlaaand");
	if (!world->win)
		return (1);
	world->img->img_ptr = mlx_new_image(world->mlx_ptr, WIDTH, HEIGHT);
	if (!world->img->img_ptr)
		return (1);
	world->img->buff = (int *)mlx_get_data_addr(world->img->img_ptr, \
		&(world->img->bpp), &(world->img->line_len), &(world->img->endian));
	if (!world->img->buff)
		return (1);
	return (0);
}

void	start(t_world *world)
{
	init_mlx(world);
	init_player(world, world->player);
	init_setup(world);
	loop(world);

}
