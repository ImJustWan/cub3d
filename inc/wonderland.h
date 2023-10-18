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

typedef struct s_hat	t_hat;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

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

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
	int		endian;
}	t_texture;

// yohai
// mcombeau -> texture.c -> get_texture_index

	// double		cam_x; // cameraX
	// double		wall_x;
	// double		wall_dist; // perpWallDist
	// t_complex	cam_plane; // planeX
	// t_complex	ray_dir; // rayDirX
	// t_complex	cur_pos; // posX then mapX
	// t_complex	side_dist; // sideDist
	// t_complex	delta_dist; // deltaDist
	// t_complex	step_dir; // stepX

typedef struct s_raycast
{
	int			draw_start;
	int			draw_end;
	int			cur_pos_x;
	int			cur_pos_y;
	int			wall_height;
	int			index_texture;
	int			x_on_tex;
	int			y_on_tex;
	double		step;
	double		cam_x;
	double		side;
	double		wall_dist;
	double		wall_pos;
	double		ray_height;
	t_complex	xpm;
	t_complex	cam_plane;
	t_complex	ray_dir;
	t_complex	side_dist;
	t_complex	delta_dist;
	t_complex	step_dir;
}	t_raycast;

typedef struct s_player
{
	t_complex	pos;
	t_complex	dir;
	t_complex	cam_plane;
	t_complex	move;
}	t_player;

typedef struct s_setup
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			*c;
	int			*f;
	int			ceiling;
	int			floor;
	t_complex	pos;
	t_complex	dir;
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

int	clean_init(t_world *world);
int	clean_exit(t_world *world);

#endif