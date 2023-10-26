/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgibier <tgibier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:42:47 by tgibier           #+#    #+#             */
/*   Updated: 2023/10/26 10:42:48 by tgibier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wonderland.h"

/*
- x goes from 0 to WIDTH
	- each iteration matches a column 1/WIDTH 
	- cam_x goes from -1 (furthest left) to 1 (furthest right) propotionnally to x
	- regle de 3 (2x -> from 0 to 2 ; -1 -> from -1 to 1)
- cam_x is 0 at start
- N / S
	- ray->ray_dir.x goes from [cam_plane.x] to -[cam_plane.x] 
	- ray->ray_dir.y stays at 
		- N stays at 1.0;
		- S stays at -1.0;
- E / W
	- ray->ray_dir.x stays at 
		- E stays at 1.0;
		- W stays at -1.0;
	- ray->ray_dir.y goes from -[cam_plane.y] to -[cam_plane.y] 
- cur_pos_x / cur_pos_y is the position of the player 
	at the start, and then after every move
- delta_dist is the hypotenuse of the triangle formed by the ray
	- x = distance traveled by the ray between two x sides
	- y = distance traveled by the ray between two y sides
		(pythagore)
		deltaX = sqrt(1 + (ray_dir.y * ray_dir.y) / (ray_dir.x * ray_dir.x))
		deltaY = sqrt(1 + (ray_dir.x * ray_dir.x) / (ray_dir.y * ray_dir.y))
			simplified to
				deltaX = abs(1 / ray_dir.x)
				deltaY = abs(1 / ray_dir.y)
- if ray->ray_dir.x or ray->ray_dir.y = 0 
	deltaX / deltaY set to INT_MAX to avoid division by 0
- N / S
	- deltaX goes from 1 to INT_MAX to 1
	- deltaY = 1 
- E / W
	- deltaX = 1 
	- deltaY goes from 1 to INT_MAX to 1

*/

void	start_raycast(t_world *world, t_raycast *ray, int x)
{
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir.x = world->player->dir.x + \
		world->player->cam_plane.x * ray->cam_x;
	ray->ray_dir.y = world->player->dir.y + \
		world->player->cam_plane.y * ray->cam_x;
	ray->cur_pos_x = (int)world->player->pos.x;
	ray->cur_pos_y = (int)world->player->pos.y;
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = INT_MAX;
	else
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = INT_MAX;
	else
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

/*
    step_dir_side_dist
    While the function start_raycast allows us to compute 
		the distance travelled between the x sides or y sides of the box, 
    	we need to compute the x and y distance between the player's position 
		and the x and y sides of the next boxes.
    Depending on the payer's orientation this function 
		computes the distance to the nearest box.
*/

void	step_dir_side_dist(t_player *player, t_raycast *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_dir.x = -1;
		ray->side_dist.x = (player->pos.x - ray->cur_pos_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_dir.x = 1;
		ray->side_dist.x = ray->delta_dist.x * \
			(ray->cur_pos_x + 1.0 - player->pos.x);
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_dir.y = -1;
		ray->side_dist.y = (player->pos.y - ray->cur_pos_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_dir.y = 1;
		ray->side_dist.y = ray->delta_dist.y * \
			(ray->cur_pos_y + 1.0 - player->pos.y);
	}
}

/*
    wall_dist_and_side
    This function compute the total length of the ray cased
		between the player and the wall.
*/

void	wall_dist_and_side(t_raycast *ray, char **map)
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
		if (ray->cur_pos_x >= (int)ft_strlen(map[ray->cur_pos_y]) \
			|| !map[ray->cur_pos_y]
			|| (map[ray->cur_pos_y][ray->cur_pos_x] == '1'))
			wall = 1;
	}
}

/*
    index_height
    This function is computing the heigth of the wall 
    depending on its distance from the player.
    It will also pick the correct texture depending on the wall orientation.
*/

void	index_height(t_world *world, t_raycast *ray)
{
	(void)world;
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->wall_height = (int)(HEIGHT / (ray->wall_dist));
	if (ray->side == 1)
	{
		if (ray->ray_dir.y < 0)
			ray->index_texture = NORTH;
		else
			ray->index_texture = SOUTH;
	}
	else
	{
		if (ray->ray_dir.x < 0)
			ray->index_texture = WEST;
		else
			ray->index_texture = EAST;
	}
}

/*
    start_end
    This function establish which stripe of texture will be used for our ray, 
    as well as the height of the textured ray 
    and where it should be printed on the screen.
*/

void	start_end(t_world *world, t_raycast *ray)
{
	if (ray->side == 0)
		ray->wall_pos = world->player->pos.y + \
			(ray->wall_dist * ray->ray_dir.y);
	else
		ray->wall_pos = world->player->pos.x + \
			(ray->wall_dist * ray->ray_dir.x);
	ray->wall_pos -= floor(ray->wall_pos);
	ray->x_on_tex = (int)(ray->wall_pos * \
		(double)world->tab_tex[ray->index_texture].width);
	if ((ray->side == 0 && ray->ray_dir.x > 0)
		|| (ray->side == 1 && ray->ray_dir.y < 0))
		ray->x_on_tex = world->tab_tex[ray->index_texture].width - 1 \
			- ray->x_on_tex;
	ray->draw_start = (-ray->wall_height / 2) + (HEIGHT / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (HEIGHT / 2) + (ray->wall_height) / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}
