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

#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "keys.h"
#include <stdlib.h>

void	draw(t_wind *win);

void	shutdown(t_wind *win, int key)
{
	int	***map;
	int	x;
	int	y;

	if (key == 53)
	{
		ft_printf("pressed the key %d *esc*\nclose\n", key);
		map = win->map;
		y = 0;
		while (map[y])
		{
			x = 0;
			while (map[y][x])
				free(map[y][x++]);
			free(map[y++]);
		}
		free(map);
		free(win);
		exit(0);
	}
}

void	rotate_x(t_wind *win, float rotate)
{
	ft_printf("rotate_x\n");
	win->angl_x += rotate;
	// win->offset_x += 20;
}

void	rotate_y(t_wind *win, float rotate)
{
	ft_printf("rotate_y\n");
	win->angl_y += rotate;
	if (rotate < 0)
		win->offset_y += 20;
	else
		win->offset_y -= 20;
}

void	rotate(t_wind *win, int key)
{
	if (key == KEY_W)
		rotate_y(win, -0.1);
	else if (key == KEY_A)
		rotate_x(win, -0.1);
	else if (key == KEY_S)
		rotate_y(win, 0.1);
	else if (key == KEY_D)
		rotate_x(win, 0.1);
	else
		return ;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw(win);
}

void	shift_x(t_wind *win, int shift)
{
	ft_printf("shift_x\n");
	win->offset_x += shift;
}

void	shift_y(t_wind *win, int shift)
{
	ft_printf("shift_x\n");
	win->offset_y += shift;
}

void	shift(t_wind *win, int key)
{
	if (key == KEY_UP)
		shift_y(win, -10);
	else if (key == KEY_LEFT)
		shift_x(win, -10);
	else if (key == KEY_DOWN)
		shift_y(win, 10);
	else if (key == KEY_RIGHT)
		shift_x(win, 10);
	else
		return ;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw(win);
}

void	zoom(t_wind *win, int key)
{
	if (key == KEY_PLUS)
	{
		ft_printf("pressed the key %d *plus*\n", key);
		win->zoom += 1;
		win->offset_y -= 10;
	}
	else if (key == KEY_MINUS )
	{
		ft_printf("pressed the key %d *minus*\n", key);
		if (win->zoom != 1)
		{
			win->zoom -= 1;
			win->offset_y += 10;
		}
	}
	else
		return ;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw(win);

}

int	key_pressed(int key, t_wind *win)
{
	shutdown(win, key);
	rotate(win, key);
	shift(win, key);
	zoom(win, key);
	// ft_printf("pressed the key %d\n", key);
	return (0);
}