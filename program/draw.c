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


//	1220 700

// mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0xFFFFFF);
	

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

void	draw_map(t_wind *win)
{
	int	***map;
	int	x;
	int	y;

	x = 0;
	y = 0;
	map = win->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			win->color = map[y][x][1];
			win->z = map[y][x][0];
			if (map[y][x + 1])
				draw_line_x(win, x, y, x + 1, y);
			if (map[y + 1])
				draw_line_x(win, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}

void	draw_vector(t_wind *win, float x1, float x2, float y1, float y2)
{
	float	step_x;
	float	step_y;
	int		max;


	step_x = x2 - x1;
	step_y = y2 - y1;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1, y1, win->color);
		x1 += step_x;
		y1 += step_y;
	}
}

void	new_vector(t_vector *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void	draw_space(t_wind *win)
{
	t_vector	*i;
	t_vector	*j;

		// draw_vector(win, 0, 1220, y - win->offset_y / 2, y + win->offset_y / 2);
		// draw_vector(win, 0, 1220, y - win->offset_y / 2, y + win->offset_y / 2);
	i = malloc(sizeof(t_vector));
	j = malloc(sizeof(t_vector));

	win->color = 0xFFFFFF;
	new_vector(i, win->offset_x + win->zoom * cos(win->angl_x), win->offset_y + win->zoom * sin(win->angl_x));
	new_vector(j, win->offset_x + win->zoom * cos(win->angl_y), win->offset_y + win->zoom * sin(win->angl_y));
	draw_vector(win, win->offset_x, i->x, win->offset_y, i->y);
	draw_vector(win, win->offset_x, j->x, win->offset_y, j->y);

	free(i);
	free(j);
}

void	draw(t_wind *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image, 0, 0);
	draw_space(win);
	// draw_map(win);
}
