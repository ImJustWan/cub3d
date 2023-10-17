#include "display.h"

void	step_and_side_dist(t_player *player, t_raycast *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (player->pos.x - ray->cur_pos_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = (ray->cur_pos_x + 1.0 - player->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (player->pos.y - ray->cur_pos_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = (ray->cur_pos_y + 1.0 - player->pos.y) * ray->delta_dist.y;
	}
}

void	current_raycast(t_world *world, t_raycast *ray, int x)
{
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = world->player->dir.x + world->player->cam_plane.x * ray->cam_plane.x ;
	ray->ray_dir.y = world->player->dir.y + world->player->cam_plane.y * ray->cam_plane.y;
	ray->cur_pos_x = world->player->pos.x; //map_x
	ray->cur_pos_y = world->player->pos.y; //map_y
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

void	more_shenanigans(t_raycast *ray)
{
	ray->wall_height = (int)(HEIGHT / ray->wall_dist); // ok
	printf("wall_height is [%d]\n", ray->wall_height);

	ray->draw_start = HEIGHT / 2 - (ray->wall_height) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (HEIGHT / 2) + (ray->wall_height) / 2;
	if (ray->side)
	{
		ray->index_texture = NORTH;
		if (ray->ray_dir.y < 0)
			ray->index_texture = SOUTH;
	}
	else
	{
		ray->index_texture = WEST;
		if (ray->ray_dir.y < 0)
			ray->index_texture = EAST;
	}
}


void	shenanigans(t_raycast *ray, char **map)
{
	int	wall;

	wall = 0;
	while (wall != 1)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->cur_pos_x += ray->step_dir.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->cur_pos_y += ray->step_dir.y;
			ray->side = 1;
		}
		if (map[ray->cur_pos_y][ray->cur_pos_x] == '1')
			wall = 1;
	}
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x; // ok

	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y; // ok

}

void	ray_pixel_put(t_img	*img, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > HEIGHT - 1 || x < 0 || x > WIDTH - 1)
		return ;
	pixel = (img->addr + (y * img->line_len + x * \
		(img->bpp / 8)));
	*(unsigned int *)pixel = color;
}

int	get_color(t_world *world, int x, int y, int i)
{
	(void)i;
	return (*(int *)(world->texture[1].addr + \
		(y * world->texture[1].line_len + x * (world->texture[1].bpp / 8))));
	// return (*(int *)(world->texture[i].addr + \
	// 	(y * world->texture[i].line_len + x * (world->texture[i].bpp / 8))));
}

void	the_actual_raycasting(t_world *world, t_raycast *ray, int x)
{
	int	y;
	int	color;

	if (ray->side == 0)
		ray->wall_pos = world->player->pos.y + ray->wall_dist * ray->ray_dir.y;
	else
		ray->wall_pos = world->player->pos.x + ray->wall_dist * ray->ray_dir.x;
	ray->wall_pos -= floor(ray->wall_pos);
	y = ray->draw_start;
	ray->ray_width = (int)(ray->wall_pos * (double)TEXTURE_WIDTH);
	printf("ray_width is [%f]\n", ray->ray_width);
	if ((ray->side == 0 && ray->ray_dir.x > 0)
		|| (ray->side == 1 && ray->ray_dir.y < 0))
		ray->ray_width = TEXTURE_WIDTH - ray->ray_width - 1;
	ray->step = 1.0 * TEXTURE_WIDTH / ray->wall_height;
	ray->ray_height = ray->step * (ray->draw_start \
		- HEIGHT / 2 + ray->wall_height / 2);
	printf("draw_end is [%d]\n", ray->draw_end);
	while (y < ray->draw_end)
	{
		color = get_color(world, ray->ray_width, ray->ray_height, ray->index_texture);
		if (x == -1)
			printf("x is [%d] y is [%d]\n", x, y);
		img_pix_put(world->img, x, y, color);
		// ray_pixel_put(world->img->img_ptr, x, y, color);
		
		ray->ray_height += ray->step;
		y++;
	}
}

// ray_height (ex depth) = tex_pos 

void	display_raycast(t_world *world, t_raycast *ray)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_raycast(world, ray);
		current_raycast(world, ray, x);
		step_and_side_dist(world->player, ray);
		shenanigans(world->ray, world->map);
		more_shenanigans(world->ray);
		the_actual_raycasting(world, ray, x);
	}
}
