#ifndef WONDERLAND_H
# define WONDERLAND_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <asm/termbits.h>
# include <sys/ioctl.h>
# include <asm/termbits.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "mlx.h"
# include "keys.h"
# include "libft.h"
# include "colors.h"

# define WIDTH  800
# define HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_raycast
{
	float	cos;
	float	sin;
	float	limit;
	float	orientation;
	float	half_cam_field;
}	t_raycast;


typedef struct s_world // WOndeRlanD
{
	void		*mlx;
	void		*win;
	float		pos_x;
	float		pos_y;
	float		player_x;
	float		player_y;
	char		**map;
	double		time;
	double		old_time;
	t_img		img;
	t_raycast	ray;

}	t_world;

int	clean_init(t_world *world);
int	clean_exit(t_world *world);

#endif