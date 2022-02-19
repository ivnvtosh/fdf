#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libgnl/get_next_line.h"
# include "../libmlx/mlx.h"

# include <stdio.h>

# define GOOD		0
# define ERROR		1
# define NOTHING	2
# define MALLOC		3
# define FD			4

# define WIDTH	1220
# define HEIGHT	700

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_frame
{
	char	*buffer;
	int		pixel;
	int		line;
	int		endian;
}	t_frame;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*screen;
}	t_mlx;

typedef struct s_map
{
	t_vector2	size;
	int			**height;
	int			**color;
}	t_map;

typedef struct s_render
{
	float		zoom;
	t_vector3	angle;
	t_vector2	offset;
	t_vector2	center;
}	t_render;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	int			mode;
	t_render	render;
	t_frame		frame;
	t_vector2	mouse;
}	t_data;

void	terminate(int code);

#endif
