#include <stdlib.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include "stdio.h"

typedef struct s_wind
{
	int		***map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		offset_x;
	int		offset_y;
	float	zoom;
	int		color;
	int		z;
	float	angl_x;
	float	angl_y;
	void	*image;
}	t_wind;

// void	draw_line_x(t_wind *win, int step_x, int step_y)
// {
// 	int	x;
// 	int	y;

// 	x = (step_x - step_y) * cos(win->angl_x);
// 	y = (step_x + step_y) * sin(win->angl_y) - win->z * win->zoom;
// 	step_x = (step_x - step_y + win->zoom) * cos(win->angl_x);
// 	while (x < step_x)
// 	{
// 		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x + win->offset_x, y + win->offset_y, win->color);
// 		x++;
// 		y++;
// 	}
// }

// void	draw_line_y(t_wind *win, int step_x, int step_y)
// {
// 	int	x;
// 	int	y;
	
// 	x = (step_x - step_y) * cos(win->angl_x);
// 	y = (step_x + step_y) * sin(win->angl_y) - win->z * win->zoom;
// 	step_y = (step_x + step_y + win->zoom) * sin(win->angl_y) - win->z * win->zoom;
// 	while (y < step_y)
// 	{
// 		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x + win->offset_x, y + win->offset_y, win->color);
// 		y++;
// 		x--;
// 	}
// }
int	ft_max(float step_x, float step_y)
{
	if (step_x < 0)
		step_x *= -1;
	if (step_y < 0)
		step_y *= -1;
	if (step_x > step_y)
		return (step_x);
	return (step_y);
}

void	draw_line_x(t_wind *win, float x1, float y1, float x2, float y2)
{
	float	step_x;
	float	step_y;
	int		color;
	int		max;
	int		z1;
	int		z2;

	z1 = win->map[(int)y1][(int)x1][0] * win->zoom / win->zoom;
	z2 = win->map[(int)y2][(int)x2][0] * win->zoom / win->zoom;
	x1 *= win->zoom;
	x2 *= win->zoom;
	y1 *= win->zoom;
	y2 *= win->zoom;
	x1 = (x1 - y1) * cos(1);
	y1 = (x1 + y1) * sin(1) - z1;
	x2 = (x2 - y2) * cos(1);
	y2 = (x2 + y2) * sin(1) - z2;
	x1 += x1 * cos(win->angl_x);
	y1 += y1 * sin(win->angl_y) - z1;
	x2 += x2 * cos(win->angl_x);
	y2 += y2 * sin(win->angl_y) - z2;
	step_x = x2 - x1;
	step_y = y2 - y1;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	if (z1 || z2)
		color = 0xDD9922;
	else
		color = win->color;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1 + win->offset_x, y1 + win->offset_y, color);
		x1 += step_x;
		y1 += step_y;
		// color += z1;
	}
}

// void	draw_line_y(t_wind *win, int step_x, int step_y)
// {

// }




void	pole(t_wind *win, float x1, float y1, float x2, float y2)
{
	float	step_x;
	float	step_y;
	int		color;
	int		max;
	// int		z1;
	// int		z2;

	// z1 = win->map[(int)y1][(int)x1][0] * win->zoom / win->zoom;
	// z2 = win->map[(int)y2][(int)x2][0] * win->zoom / win->zoom;
	// x1 *= win->zoom;
	// x2 *= win->zoom;
	// y1 *= win->zoom;
	// y2 *= win->zoom;
	x1 = (x1 - y1) * cos(1);
	y1 = (x1 + y1) * sin(1);
	x2 = (x2 - y2) * cos(1);
	y2 = (x2 + y2) * sin(1);
	x1 += x1 * cos(win->angl_x) + win->offset_x;
	y1 += y1 * sin(win->angl_y) + win->offset_y;
	x2 += x2 * cos(win->angl_x) + win->offset_x;
	y2 += y2 * sin(win->angl_y) + win->offset_y;
	step_x = x2 - x1;
	step_y = y2 - y1;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	// if (z1 || z2)
	// 	color = 0xDD9922;
	// else
	// 	color = win->color;
	color = 0x525252;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1, y1, color);
		x1 += step_x;
		y1 += step_y;
		// color -= 0x000101;
	}
}

//	1220 700

void	os_xy(t_wind *win)
{
	int	color;
	int	x;
	int	y;

	color = 0x333333;
	x = 610;
	while (x < 1220)
	{
		y = 0;
		while (y < 700)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, color);
		x += win->zoom;
	}
	x = 610;
	while (x > 0)
	{
		y = 0;
		while (y < 700)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, color);
		x -= win->zoom;
	}
	y = 350;
	while (y < 700)
	{
		x = 0;
		while (x < 1220)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x++, y, color);
		y += win->zoom;
	}
	y = 350;
	while (y > 0)
	{
		x = 0;
		while (x < 1220)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x++, y, color);
		y -= win->zoom;
	}
}

void	os_x(t_wind *win)
{
	int	x;
	int	y;

	x = 0;
	y = 350;
	while (x < 1220)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x++, y, 0xAA3333);
	x = 620;
	while (x < 1220)
	{
		y = 350 - win->zoom / 10;
		while (y < 350 + win->zoom / 10)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, 0xAA3333);
		x += win->zoom;;
	}
	x = 610;
	while (x > 0)
	{
		y = 350 - win->zoom / 10;
		while (y < 350 + win->zoom / 10)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, 0xAA3333);
		x -= win->zoom;;
	}
}

void	os_y(t_wind *win)
{
	int	x;
	int	y;

	x = 610;
	y = 0;
	while (y < 700)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, 0x33AA33);
	y = 350;
	while (y < 700)
	{
		x = 610 * win->zoom;
		while (x < 610 * win->zoom)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x++, y, 0x33AA33);
		y += win->zoom;;
	}
	y = 350;
	while (y > 0)
	{
		x = 610 * win->zoom;
		while (x < 610 * win->zoom)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x++, y, 0x33AA33);
		y -= win->zoom;;
	}
}

void	os_z(t_wind *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(void)win;
	// while (y < 700)
	// 	mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, 0x11DD11);
}

void	center(t_wind *win)
{
	int	x;
	int	y;

	x = 600;
	y = 350;
	while (x < 620)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x++, y, 0xFFFFFF);
	x = 610;
	y = 340;
	while (y < 360)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, 0xFFFFFF);
}

void	vector_x(t_wind *win, int x2)
{
	int	x;
	int	y;

	x = 610;
	y = 350;
	x2 = 610 + x2 * 10 * win->zoom / 8;
	while (x < x2)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x++, y, 0xFFFF33);
}

void	vector_y(t_wind *win, int y2)
{
	int	x;
	int	y;

	x = 610;
	y = 350;
	y2 = 350 + y2 * 10 * win->zoom / 8;
	while (y < y2)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y++, 0xFF33FF);
}

void	vector_xy(t_wind *win, float x2, float y2)
{
	float	step_x;
	float	step_y;
	int		max;
	float	x;
	float	y;

	x = 610;
	(void)x2;
	y = 350;
	y2 = 350 + y2 * 10 * win->zoom;
	x2 = 610 + x2 * 10 * win->zoom;
	step_x = x2 - x;
	step_y = y2 - y;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while (y < y2 || x < x2)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0xFFFFFF);
		// x++;
		// y++;
		x += step_x;
		y += step_y;
	}

}

typedef struct s_vector
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
}	t_vector;

void	draw_vector(t_wind *win, t_vector *vector)
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	step_x;
	float	step_y;
	int		max;

	x1 = vector->x1;
	y1 = vector->y1;
	x2 = vector->x2;
	y2 = vector->y2;
	step_x = x2 - x1;
	step_y = y2 - y1;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1, y1, 0xAA33DD);
		x1 += step_x;
		y1 += step_y;
	}
}

void	draw(t_wind *win)
{
	t_vector	*vector_i;
	t_vector	*vector_j;
	int	***map;
	int	x;
	int	y;

	x = 0;
	y = 0;
	map = win->map;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image, 0, 0);

	vector_i = malloc(sizeof(t_vector));
	vector_j = malloc(sizeof(t_vector));
	vector_i->x1 = 610;
	vector_i->y1 = 350;
	vector_i->x2 = 620 * win->zoom;
	vector_i->y2 = 350;

	vector_j->x1 = 610;
	vector_j->y1 = 350;
	vector_j->x2 = 610;
	vector_j->y2 = 360 * win->zoom;
	// os_xy(win);
	os_x(win);
	os_y(win);
	// os_z(win);
	// vector_x(win, 2);
	// vector_y(win, 3);
	// vector_xy(win, 2, 3);
	
	draw_vector(win, vector_i);
	draw_vector(win, vector_j);
	center(win);
	// while (map[y])
	// {
	// 	x = 0;
	// 	while (map[y][x])
	// 	{
	// 		win->color = map[y][x][1];
	// 		win->z = map[y][x][0];
	// 		if (map[y][x + 1])
	// 			draw_line_x(win, x, y, x + 1, y);
	// 		if (map[y + 1])
	// 			draw_line_x(win, x, y, x, y + 1);
	// 		x++;
	// 	}
	// 	y++;
	// }
	free(vector_i);
	free(vector_j);
}
