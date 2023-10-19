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

# define WIDTH  640
# define HEIGHT 480
# define TEXTURE_WIDTH 100
# define TEXTURE_HEIGHT 100

# define NORTH 0
# define SOUTH 1
# define EAST 2	
# define WEST 3

# define MOVE_SPEED 0.0125
# define ROT_SPEED 0.015

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_player
{
	int			rotate;
	t_complex	pos;
	t_complex	dir;
	t_complex	cam_plane;
	t_complex	move;
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
	int		endian;
}	t_img;



typedef struct s_setup
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			c;
	int			f;
	int			orientation;
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
	int			from_scratch;
	int			buffer[HEIGHT][WIDTH];
	int			**texture;
	t_img		*img;
	t_img		*background;
	t_player	*player;
	t_setup		*setup;
	t_raycast	*ray;
}	t_world;

int		clean_init(t_world *world);
int		clean_exit(t_world *world);

// utils.c
void	t_free(char **split);
void	ft_clear(t_list *save);

#endif