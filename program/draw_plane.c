

#include <stdlib.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include <stdio.h>

#include "struct.h"
#define RADIAN 0.01745329252

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
	v.ix = +1 * win->zoom * cos(win->angl_x * RADIAN) - +0 * win->zoom * sin(win->angl_y * RADIAN);
	v.iy = -1 * win->zoom * sin(win->angl_x * RADIAN) + -0 * win->zoom * cos(win->angl_y * RADIAN);
	v.jx = +0 * win->zoom * cos(win->angl_x * RADIAN) - +1 * win->zoom * sin(win->angl_y * RADIAN);
	v.jy = -0 * win->zoom * sin(win->angl_x * RADIAN) + -1 * win->zoom * cos(win->angl_y * RADIAN);
	v.kx = -1 * win->zoom * sin(win->angl_x * RADIAN) + +1 * win->zoom * cos(win->angl_y * RADIAN);
	v.ky = -1 * win->zoom * cos(win->angl_x * RADIAN) + +1 * win->zoom * sin(win->angl_y * RADIAN);
	win->color = 0x444444;
	draw_line(win, 0, 0, v.ox, v.oy);
	win->color = 0x5555DD;

	int		x;
	int		y;
	int ***map;

	map = win->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			v.tx = v.ox + v.ix * (x - win->centre_x) + v.jx * (y - win->centre_y) + v.kx * map[y][x][0];
			v.ty = v.oy + v.iy * (x - win->centre_x) + v.jy * (y - win->centre_y) + v.ky * map[y][x][0];
			// if (t.x >= 305 && t.x <= 905 && t.y >= 125 && t.y <= 475)
			if (v.tx >= 0 - win->zoom && v.tx <= 1220 + win->zoom && v.ty >= 0 - win->zoom && v.ty <= 700 + win->zoom)
			{
				if (map[y + 1])
					draw_line(win, v.tx, v.ty, v.tx + v.jx, v.ty + v.jy);
				if (map[y][x + 1])
					draw_line(win, v.tx, v.ty, v.tx + v.ix, v.ty + v.iy);
			}
			x++;
		}
		y++;
	}
	// win->color = 0x555555;
	// c = 600 / win->zoom + 3;
	// y = -c / 1.75;
	// while (y <= c / 1.75 + 1)
	// {
	// 	x = -c;
	// 	while (x <= c)
	// 	{
	// 		t.x = o.x + i.x * x + j.x * y;
	// 		t.y = o.y + i.y * x + j.y * y;
	// 		// draw_line(win, o.x + i.x * x,   o.y + i.y * x + j.y * y,   o.x + i.x * x + j.x,         o.y + j.y + i.y * x + j.y * y);
	// 		// draw_line(win, o.x + i.x * x,   o.y + i.y * x + j.y * y,   o.x + i.x * x + j.x + i.x,   o.y + t.y + i.y * x + j.y * y);
	// 		// draw_line(win, o.x + t.x,   o.y + t.y,   o.x + t.x + i.x,   o.y + t.y      );
	// 		if (y < c / 1.75)
	// 			draw_line(win, t.x, t.y, t.x + j.x, t.y + j.y);
	// 		if (x < c)
	// 		{
	// 			draw_line(win, t.x, t.y, t.x + i.x, t.y + i.y);
	// 			// if (y < c / 1.75)
	// 			// 	draw_line(win, t.x, t.y, t.x + j.x + i.x, t.y + i.y + j.y);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	win->color = 0x444444;
	draw_line(win, v.ox, v.oy, v.ox + v.ix + v.jx, v.oy + v.iy + v.jy);
	win->color = 0xDD5555;
	draw_line(win, v.ox, v.oy, v.ox + v.ix, v.oy + v.iy);
	win->color = 0x55DD55;
	draw_line(win, v.ox, v.oy, v.ox + v.jx, v.oy + v.jy);
	// win->color = 0x5555DD;
	win->color = 0xFFFFFF;
	draw_line(win, v.ox, v.oy, v.ox + v.kx, v.oy + v.ky);
}