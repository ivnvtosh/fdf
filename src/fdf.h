#ifndef FDF_H
# define FDF_H

# include <stdio.h>

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_ptr;

typedef struct s_map
{
	int		**height;
	int		**color;
}	t_map;

typedef struct s_angle
{
	float	x;
	float	y;
	float	z;
}	t_angle;

typedef struct s_shift
{
	float	x;
	float	y;
	float	z;
}	t_shift;

typedef struct s_centre
{
	float	x;
	float	y;
}	t_centre;

typedef struct s_render
{
	void		*frame;
	float		zoom;
	t_angle		angle;
	t_shift		shift;
	t_centre	centre;
}	t_render;

typedef struct s_mouse
{
	float	x;
	float	y;
}	t_mouse;

typedef struct s_data
{
	t_ptr		ptr;
	t_map		map;
	t_render	render;
	t_mouse		mouse;
}	t_data;

#endif