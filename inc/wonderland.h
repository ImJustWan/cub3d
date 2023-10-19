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

// typedef struct s_hat t_hat;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_player
{
	t_complex	pos;
	t_complex	dir;
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	char	*buff;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
	int		endian;
}    t_img;

typedef struct s_raycast
{
	float	cos;
	float	sin;
	float	limit;
	float	orientation;
	float	half_cam_field;
}	t_raycast;

typedef struct s_setup
	{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			c;
	int			f;
	t_complex	pos; // fill with start pos
	t_complex	dir; // fill with start dir (vector format)
}	t_setup;

typedef struct s_world // WOndeRlanD
{
	void		*mlx_ptr;
	void		*win;
	char		**map;
	double		time;
	double		old_time;
	t_img		*img;
	t_img		*background;
	t_player	*player;
	t_setup		*setup; // fill with start pos
	t_raycast	*ray;
}	t_world;

int	clean_init(t_world *world);
int	clean_exit(t_world *world);

// utils.c
void ft_free(char **split);
void    ft_clear(t_list *save);

#endif