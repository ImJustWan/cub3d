#include "hooks.h"

void	move_left(t_world *world)
{
	int		x;
	int		y;
	double	diff_x;
	double	diff_y;

	x = (int)(world->player->pos.x - \
		world->player->cam_plane.x * MOV_SPEED);
	y = (int)world->player->pos.y;
	diff_x = world->player->pos.x + \
		world->player->cam_plane.x * MOV_SPEED - 0.15;
	if (world->player->cam_plane.x < 0)
		diff_x = world->player->pos.x + \
			world->player->cam_plane.x * MOV_SPEED + 0.15;
	if (world->map[y][(int)diff_x] != '1' && world->map[y][x] != '1')
		world->player->pos.x -= world->player->cam_plane.x * MOV_SPEED;
	x = (int)world->player->pos.x;
	y = (int)(world->player->pos.y - \
		world->player->cam_plane.y * MOV_SPEED);
	diff_y = world->player->pos.y + \
		world->player->cam_plane.y * MOV_SPEED - 0.15;
	if (world->player->cam_plane.y < 0)
		diff_y = world->player->pos.y + \
			world->player->cam_plane.y * MOV_SPEED + 0.15;
	if (world->map[(int)diff_y][x] != '1' && world->map[y][x] != '1')
		world->player->pos.y -= world->player->cam_plane.y * MOV_SPEED;
}

void	move_right(t_world *world)
{
	int		x;
	int		y;
	double	diff_x;
	double	diff_y;

	x = (int)(world->player->pos.x + \
		world->player->cam_plane.x * MOV_SPEED);
	y = (int)world->player->pos.y;
	diff_x = world->player->pos.x + \
		world->player->cam_plane.x * MOV_SPEED + 0.15;
	if (world->player->cam_plane.x < 0)
		diff_x = world->player->pos.x + \
			world->player->cam_plane.x * MOV_SPEED - 0.15;
	if (world->map[y][(int)diff_x] != '1' && world->map[y][x] != '1')
		world->player->pos.x += world->player->cam_plane.x * MOV_SPEED;
	x = (int)world->player->pos.x;
	y = (int)(world->player->pos.y + \
		world->player->cam_plane.y * MOV_SPEED);
	diff_y = world->player->pos.y + \
		world->player->cam_plane.y * MOV_SPEED + 0.15;
	if (world->player->cam_plane.y < 0)
		diff_y = world->player->pos.y + \
			world->player->cam_plane.y * MOV_SPEED - 0.15;
	if (world->map[(int)diff_y][x] != '1' && world->map[y][x] != '1')
		world->player->pos.y += world->player->cam_plane.y * MOV_SPEED;
}

void	move_front(t_world *world)
{
	int		x;
	int		y;
	double	diff_x;
	double	diff_y;

	y = (int)(world->player->pos.y + world->player->dir.y * MOV_SPEED);
	x = (int)world->player->pos.x;
	diff_y = world->player->pos.y + world->player->dir.y * MOV_SPEED + 0.15;
	if (world->player->dir.y < 0)
		diff_y = world->player->pos.y + \
			world->player->dir.y * MOV_SPEED - 0.15;
	if (world->map[(int)diff_y][x] != '1' && world->map[y][x] != '1')
		world->player->pos.y += world->player->dir.y * MOV_SPEED;
	y = (int)world->player->pos.y;
	x = (int)(world->player->pos.x + world->player->dir.x * MOV_SPEED);
	diff_x = world->player->pos.x + world->player->dir.x * MOV_SPEED + 0.15;
	if (world->player->dir.x < 0)
		diff_x = world->player->pos.x + \
			world->player->dir.x * MOV_SPEED - 0.15;
	if (world->map[y][(int)diff_x] != '1' && world->map[y][x] != '1')
		world->player->pos.x += world->player->dir.x * MOV_SPEED;
}

void	move_back(t_world *world)
{
	int		x;
	int		y;
	double	diff_x;
	double	diff_y;

	y = (int)(world->player->pos.y - world->player->dir.y * MOV_SPEED);
	x = (int)world->player->pos.x;
	diff_y = world->player->pos.y - world->player->dir.y * MOV_SPEED - 0.15;
	if (world->player->dir.y < 0)
		diff_y = world->player->pos.y + \
			world->player->dir.y * MOV_SPEED + 0.15;
	if (world->map[(int)diff_y][x] != '1' && world->map[y][x] != '1')
		world->player->pos.y -= world->player->dir.y * MOV_SPEED;
	y = (int)world->player->pos.y;
	x = (int)(world->player->pos.x - world->player->dir.x * MOV_SPEED);
	diff_x = world->player->pos.x + world->player->dir.x * MOV_SPEED - 0.15;
	if (world->player->dir.x < 0)
		diff_x = world->player->pos.x + \
			world->player->dir.x * MOV_SPEED + 0.15;
	if (world->map[y][(int)diff_x] != '1' && world->map[y][x] != '1')
		world->player->pos.x -= world->player->dir.x * MOV_SPEED;
}

void	move_player(t_world *world, t_player *player)
{
	if (player->move.x == 1)
		move_right(world);
	if (player->move.x == -1)
		move_left(world);
	if (player->move.y == 1)
		move_front(world);
	if (player->move.y == -1)
		move_back(world);
}
