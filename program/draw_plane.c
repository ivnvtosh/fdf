
#include "fdf.h"

static int	ft_max(float step_x, float step_y)
{
	if (step_x < 0)
		step_x *= -1;
	if (step_y < 0)
		step_y *= -1;
	if (step_x > step_y)
		return (step_x);
	return (step_y);
}

void	draw_line(t_wind *win, float x, float y, float x1, float y1)
{
	float	step_x;
	float	step_y;
	int		max;

	step_x = x1 - x;
	step_y = y1 - y;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->color);
		x += step_x;
		y += step_y;
	}
}
struct s_vector
{
	float	ox;
	float	oy;
	float	ix;
	float	iy;
	float	jx;
	float	jy;
	float	kx;
	float	ky;
	float	tx;
	float	ty;
};

void	draw_plane(t_wind *win)
{
	struct s_vector	v;

	v.ox = win->offset_x;
	v.oy = win->offset_y;
	v.ix = 1 * win->zoom;
	v.iy = 0;

	v.jx = 0;
	v.jy = 1 * win->zoom;

	// v.kx = -1 * win->zoom * sin(win->angl_x * RADIAN) ;
	// v.ky = -1 * win->zoom * cos(win->angl_x * RADIAN) ;

	win->color = 0x444444;
	draw_line(win, 0, 0, v.ox, v.oy);
	win->color = 0x5555DD;

	int		x;
	int		y;
	int		step;
	int ***map;

	map = win->map;
	y = 0;
	if (win->zoom < 6)
		step = win->step;
	else
		step = 1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			v.tx = v.ox + v.ix * (x - win->centre_x) + v.jx * (y - win->centre_y);
			v.ty = v.oy + v.iy * (x - win->centre_x) + v.jy * (y - win->centre_y) - 1 * map[y][x][0];
			// if (v.tx >= 305 && v.tx <= 905 && v.ty >= 125 && v.ty <= 475)
			if (v.tx >= 0 - win->zoom && v.tx <= 1220 + win->zoom && v.ty >= 0 - win->zoom && v.ty <= 700 + win->zoom)
			{
				if (map[y][x][0] > 80)
					win->color = 0x6666EE;
				else
					win->color = 0x5555DD;
				if (map[y + 1])
					draw_line(win, v.tx, v.ty, v.tx + v.jx * step, v.ty + v.jy * step);
				if (map[y][x + 1])
					draw_line(win, v.tx, v.ty, v.tx + v.ix * step, v.ty + v.iy * step);
			}
			x += step;
		}
		y += step;
	}
	win->color = 0x444444;
	draw_line(win, v.ox, v.oy, v.ox + v.ix + v.jx, v.oy + v.iy + v.jy);
	win->color = 0xDD5555;
	draw_line(win, v.ox, v.oy, v.ox + v.ix, v.oy + v.iy);
	win->color = 0x55DD55;
	draw_line(win, v.ox, v.oy, v.ox + v.jx, v.oy + v.jy);
	// win->color = 0x5555DD;
	// win->color = 0xFFFFFF;
	// draw_line(win, v.ox, v.oy, v.ox + v.kx, v.oy + v.ky);
}