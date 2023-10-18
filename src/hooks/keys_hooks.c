#include "keys.h"
#include "hooks.h"

void	left_right(t_world *world, t_move move)
{
	int	x;
	int	y;

	if (move == left)
	{
		x = (int)world->player->pos.x - world->player->cam_plane.x * MOVE_SPEED;
		y = (int)world->player->pos.y - world->player->cam_plane.y * MOVE_SPEED;
		if (x < WIDTH && y < HEIGHT && world->map[x][y] != '1')
		{
			world->player->pos.x -= world->player->cam_plane.x * MOVE_SPEED;
			world->player->pos.y -= world->player->cam_plane.y * MOVE_SPEED;
		}
	}
	if (move == right)
	{
		x = (int)world->player->pos.x + world->player->cam_plane.x * MOVE_SPEED;
		y = (int)world->player->pos.y + world->player->cam_plane.y * MOVE_SPEED;
		if (x < WIDTH && y < HEIGHT && world->map[x][y] != '1')
		{
			world->player->pos.x += world->player->cam_plane.x * MOVE_SPEED;
			world->player->pos.y += world->player->cam_plane.y * MOVE_SPEED;
		}
	}
}

void	front_back(t_world *world, t_move move)
{
	int	x;
	int	y;

	if (move == front)
	{
		x = (int)world->player->pos.x + world->player->dir.x * MOVE_SPEED;
		y = (int)world->player->pos.y + world->player->dir.y * MOVE_SPEED;
		if (x < WIDTH && y < HEIGHT && world->map[x][y] != '1')
		{
			world->player->pos.x += world->player->dir.x * MOVE_SPEED;
			world->player->pos.y += world->player->dir.y * MOVE_SPEED;
		}
	}
	if (move == back)
	{
		x = (int)world->player->pos.x - world->player->dir.x * MOVE_SPEED;
		y = (int)world->player->pos.y - world->player->dir.y * MOVE_SPEED;
		if (x < WIDTH && y < HEIGHT && world->map[x][y] != '1')
		{
			world->player->pos.x -= world->player->dir.x * MOVE_SPEED;
			world->player->pos.y -= world->player->dir.y * MOVE_SPEED;
		}
	}
}

void	move_player(t_world *world)
{
	if (world->player->move.x == 1)
		left_right(world, right);
	if (world->player->move.x == -1)
		left_right(world, left);
	if (world->player->move.y == 1)
		front_back(world, front);
	if (world->player->move.y == -1)
		front_back(world, back);
}

int	keys_release(int button, t_world *world)
{
	if (button == KEY_W && world->player->move.y == 1)
		world->player->move.y = 0;
	if (button == KEY_A && world->player->move.x == -1)
		world->player->move.x = 0;
	if (button == KEY_S && world->player->move.y == -1)
		world->player->move.y = 0;
	if (button == KEY_D && world->player->move.x == 1)
		world->player->move.x = 0;
	return (0);
}

int	keys_press(int button, t_world *world)
{
	if (button == ESC)
		clean_exit(world);
	if (button == KEY_W)
		world->player->move.y = 1;
	if (button == KEY_A)
		world->player->move.x = -1;
	if (button == KEY_S)
		world->player->move.y = -1;
	if (button == KEY_D)
		world->player->move.x = 1;
	return (0);
}
