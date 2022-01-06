
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
	struct s_vector	Mx;
	struct s_vector	My;
	struct s_vector	Mz;
	// struct s_vector	v;

	win->color = 0x444444;
	draw_line(win, -win->offset_x, -win->offset_y, 0, 0);
	win->color = 0x5555DD;


















	Mx.ix = 1;
	Mx.iy = 0;
	Mx.iz = 0;

	Mx.jx = 0;
	Mx.jy = cos(win->angl_x * RADIAN);
	Mx.jy = sin(win->angl_x * RADIAN);

	Mx.kx = 0;
	Mx.ky = -sin(win->angl_x * RADIAN);
	Mx.kz = cos(win->angl_x * RADIAN);



	My.ix = cos(win->angl_y * RADIAN);
	My.iy = 0;
	My.iz = -sin(win->angl_y * RADIAN);

	My.jx = 0;
	My.jy = 1;
	My.jy = 0;

	My.kx = sin(win->angl_y * RADIAN);
	My.ky = 0;
	My.kz = cos(win->angl_y * RADIAN);



	Mz.ix = cos(win->angl_z * RADIAN);
	Mz.iy = sin(win->angl_z * RADIAN);
	Mz.iz = 0;

	Mz.jx = -sin(win->angl_z * RADIAN);
	Mz.jy = cos(win->angl_z * RADIAN);
	Mz.jy = 0;

	Mz.kx = 0;
	Mz.ky = 0;
	Mz.kz = 1;



	int	a;
	int	b;

	//	i
	a = win->zoom * ( cos(win->angl_y * RADIAN) + sin(win->angl_y * RADIAN));
	b = win->zoom * (-sin(win->angl_y * RADIAN) + cos(win->angl_y * RADIAN));
	win->color = 0xDD5555;
	draw_line(win, 0, 0, a, b);

	//	j
	a = win->zoom * ( cos(win->angl_x * RADIAN) + sin(win->angl_x * RADIAN));
	b = win->zoom * (-sin(win->angl_x * RADIAN) + cos(win->angl_x * RADIAN));
	win->color = 0x55DD55;
	draw_line(win, 0, 0, a, b);

	//	k
	a = win->zoom * ( cos(win->angl_z * RADIAN) - sin(win->angl_z * RADIAN));
	b = win->zoom * (-sin(win->angl_z * RADIAN) + cos(win->angl_z * RADIAN));
	win->color = 0x5555DD;
	draw_line(win, 0, 0, a, b);

	// //	sum
	// win->color = 0xFFFFFF;
	// draw_line(win, 0, 0, );








	// int		x;
	// int		y;
	// int ***map;

	// map = win->map;
	// y = 0;

	// while (map[y])
	// {
	// 	x = 0;
	// 	while (map[y][x])
	// 	{
	// 		v.tx = v.ix * (x - win->centre_x) + v.jx * (y - win->centre_y) + v.kx * map[y][x][0];
	// 		v.ty = v.iy * (x - win->centre_x) + v.jy * (y - win->centre_y) + v.ky * map[y][x][0];

	// 		if (map[y + 1])
	// 			draw_line(win, v.tx, v.ty, v.tx + v.jx, v.ty + v.jy);
	// 		if (map[y][x + 1])
	// 			draw_line(win, v.tx, v.ty, v.tx + v.ix, v.ty + v.iy);
	// 		x += 1;
	// 	}
	// 	y += 1;
	// }

	// win->color = 0x444444;
	// draw_line(win, v.ox, v.oy, v.ox + v.ix + v.jx, v.oy + v.iy + v.jy);












	// fig->matrix[0][0]=(1-cos(angle))*(x*x-1)+1;
    // fig->matrix[0][1]=sin(angle)*z+(1-cos(angle))*x*y;
    // fig->matrix[0][2]=(1-cos(angle))*x*z-sin(angle)*y;
    // fig->matrix[0][3]=0;
 
    // fig->matrix[1][0]=(1-cos(angle))*x*y-sin(angle)*z;
    // fig->matrix[1][1]=(1-cos(angle))*(y*y-1)+1;
    // fig->matrix[1][2]=(1-cos(angle))*y*z+sin(angle)*x;
    // fig->matrix[1][3]=0;
 
    // fig->matrix[2][0]=(1-cos(angle))*x*z+sin(angle)*y;
    // fig->matrix[2][1]=(1-cos(angle))*y*z-sin(angle)*x;
    // fig->matrix[2][2]=(1-cos(angle))*(z*z-1)+1;
    // fig->matrix[2][3]=0;
 
    // fig->matrix[3][0]=0;
    // fig->matrix[3][1]=0;
    // fig->matrix[3][2]=0;
    // fig->matrix[3][3]=1;












	// v.ix =  0;
	// v.iy =  win->zoom * cos(win->angl_x * RADIAN) + win->zoom * sin(win->angl_x * RADIAN);
	// v.iz = -win->zoom * sin(win->angl_x * RADIAN) + win->zoom * cos(win->angl_x * RADIAN);

	// v.jx =  win->zoom * cos(win->angl_y * RADIAN) + win->zoom * sin(win->angl_y * RADIAN);
	// v.jy =  0;
	// v.jy = -win->zoom * sin(win->angl_y * RADIAN) + win->zoom * cos(win->angl_y * RADIAN);

	// v.kx =  win->zoom * cos(win->angl_z * RADIAN) + win->zoom * sin(win->angl_z * RADIAN);
	// v.ky = -win->zoom * sin(win->angl_z * RADIAN) + win->zoom * cos(win->angl_z * RADIAN);
	// v.kz =  0;

	// // fig->matrix[0][0]=(1-cos(angle))*(x*x-1)+1;
    // // fig->matrix[0][1]=sin(angle)*z+(1-cos(angle))*x*y;
    // // fig->matrix[0][2]=(1-cos(angle))*x*z-sin(angle)*y;
    // // fig->matrix[0][3]=0;
 
    // // fig->matrix[1][0]=(1-cos(angle))*x*y-sin(angle)*z;
    // // fig->matrix[1][1]=(1-cos(angle))*(y*y-1)+1;
    // // fig->matrix[1][2]=(1-cos(angle))*y*z+sin(angle)*x;
    // // fig->matrix[1][3]=0;
 
    // // fig->matrix[2][0]=(1-cos(angle))*x*z+sin(angle)*y;
    // // fig->matrix[2][1]=(1-cos(angle))*y*z-sin(angle)*x;
    // // fig->matrix[2][2]=(1-cos(angle))*(z*z-1)+1;
    // // fig->matrix[2][3]=0;
 
    // // fig->matrix[3][0]=0;
    // // fig->matrix[3][1]=0;
    // // fig->matrix[3][2]=0;
    // // fig->matrix[3][3]=1;

	// //	i
	// v.tx = (1 * v.ix) + (0 * v.jx) + (0 * v.kx);
	// v.ty = (1 * v.iy) + (0 * v.jy) + (0 * v.ky);
	// v.tz = (1 * v.iz) + (0 * v.jz) + (0 * v.kz);
	// win->color = 0xDD5555;
	// draw_line(win, 0, 0, v.tx, v.ty);

	// //	j
	// v.tx = (0 * v.ix) + (1 * v.jx) + (0 * v.kx);
	// v.ty = (0 * v.iy) + (1 * v.jy) + (0 * v.ky);
	// v.tz = (0 * v.iz) + (1 * v.jz) + (0 * v.kz);
	// win->color = 0x55DD55;
	// draw_line(win, 0, 0, v.tx, v.ty);


	// //	k
	// v.tx = (0 * v.ix) + (0 * v.jx) + (1 * v.kx);
	// v.ty = (0 * v.iy) + (0 * v.jy) + (1 * v.ky);
	// v.tz = (0 * v.iz) + (0 * v.jz) + (1 * v.kz);
	// win->color = 0x5555DD;
	// draw_line(win, 0, 0, 0, 0);


	// //	sum
	// v.tx = v.ix + v.iy + v.iz;
	// v.ty = v.jx + v.jy + v.jz;
	// v.tz = v.kx + v.ky + v.kz;
	// win->color = 0xFFFFFF;
	// draw_line(win, 0, 0, v.tx, v.ty);





















	// v.ix =  0;
	// v.iy =  win->zoom * cos(win->angl_x * RADIAN) + win->zoom * sin(win->angl_x * RADIAN);
	// v.iz =  win->zoom * sin(win->angl_x * RADIAN) + win->zoom * cos(win->angl_x * RADIAN);

	// v.jx =  win->zoom * cos(win->angl_y * RADIAN) + win->zoom * sin(win->angl_y * RADIAN);
	// v.jy =  0;
	// v.jy = -win->zoom * sin(win->angl_y * RADIAN) + win->zoom * cos(win->angl_y * RADIAN);

	// v.kx =  win->zoom * cos(win->angl_z * RADIAN) - win->zoom * sin(win->angl_z * RADIAN);
	// v.ky =  win->zoom * sin(win->angl_z * RADIAN) + win->zoom * cos(win->angl_z * RADIAN);
	// v.kz =  0;


	// //	i
	// v.tx = (1 * v.ix) + (1 * v.jx) + (1 * v.kx);
	// v.ty = (0 * v.iy) + (0 * v.jy) + (0 * v.ky);
	// v.tz = (0 * v.iz) + (0 * v.jz) + (0 * v.kz);
	// win->color = 0xDD5555;
	// draw_line(win, 0, 0, v.tx, v.ty);


	// //	j
	// v.tx = (0 * v.ix) + (0 * v.jx) + (0 * v.kx);
	// v.ty = (1 * v.iy) + (1 * v.jy) + (1 * v.ky);
	// v.tz = (0 * v.iz) + (0 * v.jz) + (0 * v.kz);
	// win->color = 0x55DD55;
	// draw_line(win, 0, 0, v.ty, v.ty);


	// //	k
	// v.tx = (0 * v.ix) + (0 * v.jx) + (0 * v.kx);
	// v.ty = (0 * v.iy) + (0 * v.jy) + (0 * v.ky);
	// v.tz = (1 * v.iz) + (1 * v.jz) + (1 * v.kz);
	// win->color = 0x5555DD;
	// draw_line(win, 0, 0, v.tz, v.tz - v.kz);


	// //	sum
	// v.tx = v.ix + v.iy + v.iz;
	// v.ty = v.jx + v.jy + v.jz;
	// v.tz = v.kx + v.ky + v.kz;
	// win->color = 0xFFFFFF;
	// draw_line(win, 0, 0, v.tx, v.ty);


































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






















































}