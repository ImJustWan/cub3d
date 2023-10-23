#include "display.h"
#include "hooks.h"


int	loop(t_world *world)
{
	int i = -1;
	display_init(world);
	while (world->map[++i])
		printf("map[%d] is [%s]\n", i, world->map[i]);
	mlx_hook(world->win, DESTROY, 0, clean_exit, world);
	mlx_hook(world->win, KeyPress, KeyPressMask, keys_press, world);
	mlx_hook(world->win, KeyRelease, KeyReleaseMask, keys_release, world);
	display_raycast(world);
	mlx_loop_hook(world->mlx_ptr, display_raycast, world);
	mlx_loop(world->mlx_ptr);
	return (0);
}
/*

	// display_background(world);
	// mlx_put_image_to_window(world, world->win, world->img->img_ptr, 0, 0);

funnsies

	world->texture[i].img_ptr = mlx_xpm_file_to_image(world->mlx_ptr, \
		"x_north.xpm", &(texture[i].width), &(texture[i].height));
	if (!world->texture[i].img_ptr)
		return (1);
	world->texture[i].addr = mlx_get_data_addr(texture[i].img_ptr, \
		&(texture[i].bpp), &(texture[i].line_len), &(texture[i].endian));
	if (!world->texture[i].addr)

	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[0].img_ptr, (WIDTH / 2) - (world->texture[0].width / 2), 100);
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[1].img_ptr, (WIDTH / 2) - (world->texture[1].width / 2), 275);
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[2].img_ptr, (WIDTH / 2) - (world->texture[2].width / 2), 450);
	mlx_put_image_to_window(world->mlx_ptr, world->win, \
		world->texture[3].img_ptr, (WIDTH / 2) - (world->texture[3].width / 2), 625);


*/
