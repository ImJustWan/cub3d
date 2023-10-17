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

int	init_raycast(t_world *world, t_raycast *ray)
{
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->cam_x = 0;
	ray->side = 0;
	ray->wall_pos = 0; // perp_wall_dist
	ray->wall_dist = 0; // perp_wall_dist
	ray->cam_plane.x = 0;
	ray->cam_plane.y = 0;
	ray->ray_dir.x = 0;
	ray->ray_dir.y = 0;
	ray->cur_pos_x = world->setup->pos.x;
	ray->cur_pos_y = world->setup->pos.y;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = 0;
	ray->delta_dist.y = 0;
	ray->step_dir.x = 0;
	ray->step_dir.y = 0;
	ray->xpm.x = 0;
	ray->xpm.y = 0;
	ray->index_texture = 0;
	ray->wall_height = 0;
	ray->ray_height = 0;
	return (0);
}

int	init_setup(t_world *world, t_setup *setup)
{
	(void)world;
	setup->ceiling = ft_encode_rgb(102, 0, 102);
	setup->floor = ft_encode_rgb(255, 153, 51);
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
	world->img->addr = mlx_get_data_addr(world->img->img_ptr, \
		&(world->img->bpp), &(world->img->line_len), &(world->img->endian));
	if (!world->img->addr)
		return (1);
	return (0);
}


void	*ft_ze_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	unsigned int	i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	array = (unsigned char *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		array[i] = '\0';
		i++;
	}
	return ((void *)array);
}

void	fake_init(t_world *world)
{
	int	i;

	world->map = ft_ze_calloc(6, sizeof(char *));
	i = -1;
	while (++i < 5)
		world->map[i] = ft_ze_calloc(6, sizeof(char));
	i = -1;
	while (++i < 5)
	{
		if (i == 0)
			world->map[i] = "11111";
		else if (i == 2)
			world->map[i] = "10N01";
		else if (i == 4)
			world->map[i] = "11111";
		else
			world->map[i] = "10001";
	}
	// NORTH
	world->player->pos.x = 2.5;
	world->player->pos.y = 2.5;
	world->player->dir.x = 0;
	world->player->dir.y = -1;
	world->player->cam_plane.x = 0.66;
	world->player->cam_plane.y = 0;
}

void	display_init(t_world *world)
{
	init_mlx(world);
	init_raycast(world, world->ray);
	init_setup(world, world->setup);
	init_player(world, world->player);
	init_textures(world, world->texture);
	fake_init(world);
}
