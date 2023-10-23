#include "hooks.h"

void	left_right(t_world *world, t_move move)
{
	int	x;
	int	y;

	if (move == left)
	{
		x = (int)world->player->pos.x - world->player->cam_plane.x * MOV_SPEED;
		y = (int)world->player->pos.y;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.x -= world->player->cam_plane.x * MOV_SPEED;
		y = (int)world->player->pos.y - world->player->cam_plane.y * MOV_SPEED;
		x = (int)world->player->pos.x;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.y -= world->player->cam_plane.y * MOV_SPEED;
	}
	if (move == right)
	{
		x = (int)world->player->pos.x + world->player->cam_plane.x * MOV_SPEED;
		y = (int)world->player->pos.y;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.x += world->player->cam_plane.x * MOV_SPEED;
		y = (int)world->player->pos.y + world->player->cam_plane.y * MOV_SPEED;
		x = (int)world->player->pos.x;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.y += world->player->cam_plane.y * MOV_SPEED;
	}
}

void	front_back(t_world *world, t_move move)
{
	int	x;
	int	y;

	if (move == front)
	{
		y = (int)world->player->pos.y + world->player->dir.y * MOV_SPEED;
		x = (int)world->player->pos.x;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.y += world->player->dir.y * MOV_SPEED;
		x = (int)world->player->pos.x + world->player->dir.x * MOV_SPEED;
		y = (int)world->player->pos.y;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.x += world->player->dir.x * MOV_SPEED;
	}
	if (move == back)
	{
		y = (int)world->player->pos.y - world->player->dir.y * MOV_SPEED;
		x = (int)world->player->pos.x;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.y -= world->player->dir.y * MOV_SPEED;
		x = (int)world->player->pos.x - world->player->dir.x * MOV_SPEED;
		y = (int)world->player->pos.y;
		if (x < WIDTH && y < HEIGHT && world->map[y][x] != '1')
			world->player->pos.x -= world->player->dir.x * MOV_SPEED;
	}
}

void	move_player(t_world *world, t_player *player)
{
	if (player->move.x == 1)
		left_right(world, right);
	if (player->move.x == -1)
		left_right(world, left);
	if (player->move.y == 1)
		front_back(world, front);
	if (player->move.y == -1)
		front_back(world, back);
}
