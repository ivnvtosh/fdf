
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
	x += win->offset_x;
	y += win->offset_y;
	x1 += win->offset_x;
	y1 += win->offset_y;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->color);
		x += step_x;
		y += step_y;
	}
}
struct s_vector
{
	float	ix;
	float	iy;
	float	iz;

	float	jx;
	float	jy;
	float	jz;

	float	kx;
	float	ky;
	float	kz;

	float	tx;
	float	ty;
	float	tz;
};

void	draw_plane(t_wind *win)
{
	struct s_vector	v;

	v.ix =  0;
	v.iy =  win->zoom * cos(win->angl_x * RADIAN) + win->zoom * sin(win->angl_x * RADIAN);
	v.iz =  win->zoom * sin(win->angl_x * RADIAN) + win->zoom * cos(win->angl_x * RADIAN);

	v.jx =  win->zoom * cos(win->angl_y * RADIAN) + win->zoom * sin(win->angl_y * RADIAN);
	v.jy =  0;
	v.jy = -win->zoom * sin(win->angl_y * RADIAN) + win->zoom * cos(win->angl_y * RADIAN);

	v.kx = win->zoom * cos(win->angl_z * RADIAN) - win->zoom * sin(win->angl_z * RADIAN);
	v.ky = win->zoom * sin(win->angl_z * RADIAN) + win->zoom * cos(win->angl_z * RADIAN);
	v.kz =  0;

	// x'=x*cos(L)-y*sin(L);
	// y'=-x*sin(L)+y*cos(L);
	// z'=z;

	win->color = 0x444444;
	draw_line(win, -win->offset_x, -win->offset_y, 0, 0);
	win->color = 0x5555DD;

	// int		x;
	// int		y;
	// int		step;
	// int ***map;

	// map = win->map;
	// y = 0;
	// if (win->zoom < 6)
	// 	step = win->step;
	// else
	// 	step = 1;
	// while (map[y])
	// {
	// 	x = 0;
	// 	while (map[y][x])
	// 	{
	// 		v.tx = v.ox + v.ix * (x - win->centre_x) + v.jx * (y - win->centre_y) + v.kx * map[y][x][0];
	// 		v.ty = v.oy + v.iy * (x - win->centre_x) + v.jy * (y - win->centre_y) + v.ky * map[y][x][0];
	// 		// if (v.tx >= 305 && v.tx <= 905 && v.ty >= 125 && v.ty <= 475)
	// 		if (v.tx >= 0 - win->zoom && v.tx <= 1220 + win->zoom && v.ty >= 0 - win->zoom && v.ty <= 700 + win->zoom)
	// 		{
	// 			if (map[y][x][0] > 80)
	// 				win->color = 0x6666EE;
	// 			else
	// 				win->color = 0x5555DD;
	// 			if (map[y + 1])
	// 				draw_line(win, v.tx, v.ty, v.tx + v.jx * step, v.ty + v.jy * step);
	// 			if (map[y][x + 1])
	// 				draw_line(win, v.tx, v.ty, v.tx + v.ix * step, v.ty + v.iy * step);
	// 		}
	// 		x += step;
	// 	}
	// 	y += step;
	// }

	// win->color = 0x444444;
	// draw_line(win, v.ox, v.oy, v.ox + v.ix + v.jx, v.oy + v.iy + v.jy);
























	//	i
	v.tx = (1 * v.ix) + (1 * v.jx) + (1 * v.kx);
	v.ty = (0 * v.iy) + (0 * v.jy) + (0 * v.ky);
	v.tz = (0 * v.iz) + (0 * v.jz) + (0 * v.kz);
	win->color = 0xDD5555;
	draw_line(win, 0, 0, v.tx + win->zoom, v.ty);
	printf("\ni\n");
	printf("x * y = %f\n", v.tx * v.ty);
	printf("x * z = %f\n", v.tx * v.tz);
	printf("y * z = %f\n", v.ty * v.tz);

	//	j
	v.tx = (0 * v.ix) + (0 * v.jx) + (0 * v.kx);
	v.ty = (1 * v.iy) + (1 * v.jy) + (1 * v.ky);
	v.tz = (0 * v.iz) + (0 * v.jz) + (0 * v.kz);
	win->color = 0x55DD55;
	draw_line(win, 0, 0, v.ty, v.ty + win->zoom);
	printf("\nj\n");
	printf("x * y = %f\n", v.tx * v.ty);
	printf("x * z = %f\n", v.tx * v.tz);
	printf("y * z = %f\n", v.ty * v.tz);

	//	k
	v.tx = (0 * v.ix) + (0 * v.jx) + (0 * v.kx);
	v.ty = (0 * v.iy) + (0 * v.jy) + (0 * v.ky);
	v.tz = (1 * v.iz) + (1 * v.jz) + (1 * v.kz);
	win->color = 0x5555DD;
	draw_line(win, 0, 0, v.tz, v.tz - v.kz);
	printf("\nk\n");
	printf("x * y = %f\n", v.tx * v.ty);
	printf("x * z = %f\n", v.tx * v.tz);
	printf("y * z = %f\n", v.ty * v.tz);

	//	sum
	v.tx = v.ix + v.iy + v.iz;
	v.ty = v.jx + v.jy + v.jz;
	v.tz = v.kx + v.ky + v.kz;
	win->color = 0xFFFFFF;
	draw_line(win, 0, 0, v.tx, v.ty);
	printf("\nsum\n");
	printf("x * y = %f\n", v.tx * v.ty);
	printf("x * z = %f\n", v.tx * v.tz);
	printf("y * z = %f\n", v.ty * v.tz);





























}