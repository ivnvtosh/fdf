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
	int		zoom;
	int		color;
	int		z;
	float	angl_x;
	float	angl_y;
}	t_wind;

void	draw_line_x(t_wind *win, int step_x, int step_y)
{
	int	x;
	int	y;

	x = (step_x - step_y) * cos(win->angl_x);
	y = (step_x + step_y) * sin(win->angl_y) - win->z * win->zoom;
	step_x = (step_x - step_y + win->zoom) * cos(win->angl_x);
	while (x < step_x)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x + win->offset_x, y + win->offset_y, win->color);
		x++;
		y++;
	}
}

void	draw_line_y(t_wind *win, int step_x, int step_y)
{
	int	x;
	int	y;
	
	x = (step_x - step_y) * cos(win->angl_x);
	y = (step_x + step_y) * sin(win->angl_y) - win->z * win->zoom;
	step_y = (step_x + step_y + win->zoom) * sin(win->angl_y) - win->z * win->zoom;
	while (y < step_y)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x + win->offset_x, y + win->offset_y, win->color);
		y++;
		x--;
	}
}


void	draw(t_wind *win)
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
			win->color = map[y][x][1] + win->z * 200;
			win->z = map[y][x][0];
			if (map[y][x + 1])
				draw_line_x(win, x * win->zoom, y * win->zoom);
			if (map[y + 1])
				draw_line_y(win, x * win->zoom, y * win->zoom);
			x++;
		}
		y++;
	}
}
