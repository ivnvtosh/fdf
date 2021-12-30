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
#include <math.h>
#define	UP 5
#define	LEFT 7
#define	DOWN 4
#define	RIGHT 6
void	draw(t_wind *win);

static void	rotate_x(t_wind *win, float rotate)
{
	ft_printf("rotate_x_mouse\n");
	win->angl_x += rotate;
	// win->offset_x += 20;
}

static void	rotate_y(t_wind *win, float rotate)
{
	ft_printf("rotate_y_mouse\n");
	win->angl_y += rotate;
	if (rotate < 0)
		win->offset_y += 20;
	else
		win->offset_y -= 20;
}

void	rotate_mouse(t_wind *win, int key)
{
	if (key == UP)
		rotate_y(win, -0.1);
	else if (key == LEFT)
		rotate_x(win, -0.1);
	else if (key == DOWN)
		rotate_y(win, 0.1);
	else if (key == RIGHT)
		rotate_x(win, 0.1);
	else
		return ;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw(win);
}

int	mouse_pressed_lol(int x, int y, t_wind *win)
{
	static int	x1;
	static int	y1;

	if (y - y1 > 100)
		y1 = y;
	if (y1 - y > 100)
		y1 = y;
	if (y - y1 > 0)
	{
		win->angl_y += (y - y1) * 0.01;
		// win->offset_y -= (y * 1.1 - y1 * 1.1);
	}

	else
	{
		win->angl_y -= (y1 - y) * 0.01;
		// win->offset_y += (y1 * 1.1 - y * 1.1);
	}
	if (x - x1 > 100)
		x1 = x;
	if (x1 - x > 100)
		x1 = x;
	if (x - x1 > 0)
		win->angl_x += (x - x1) * 0.01;
	else
		win->angl_x -= (x1 - x) * 0.01;
	y1 = y;
	x1 = x;
	ft_printf("*nothing* x-%d y-%d \n", x, y);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw(win);
	return (x + y);
}

int	mouse_pressed_shift(int x, int y, t_wind *win)
{
	static int	x1;
	static int	y1;

	if (y - y1 > 50)
		y1 = y;
	if (y1 - y > 50)
		y1 = y;
	if (y - y1 > 0)
	{
		win->offset_y += (y - y1);
	}

	else
	{
		win->offset_y -= (y1 - y) ;
	}
	if (x - x1 > 50)
		x1 = x;
	if (x1 - x > 50)
		x1 = x;
	if (x - x1 > 0)
		win->offset_x += (x - x1);
	else
		win->offset_x -= (x1 - x);
	y1 = y;
	x1 = x;
	ft_printf("*nothing* x-%d y-%d \n", x, y);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw(win);
	return (x + y);
}

void	zoom_mouse(t_wind *win, int key)
{
	if (key == UP)
	{
		ft_printf("pressed the key %d *plus*\n", key);
		win->zoom += 1;
		win->offset_y -= 10;
	}
	else if (key == DOWN)
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

int	mouse_pressed(int key, int x, int y, t_wind *win)
{
	ft_printf("pressed the key %d *nothing* x-%d y-%d \n", key, x, y);
	if (key == 1)
	{
		mlx_hook(win->win_ptr, 6, 0, mouse_pressed_shift, win);
		ft_printf("pressed the key %d *left click* x-%d y-%d \n", key, x, y);
	}
	else if (key == 2)
	{
		mlx_hook(win->win_ptr, 6, 0, mouse_pressed_lol, win);
		ft_printf("pressed the key %d *right click* x-%d y-%d \n", key, x, y);
	}
		
	zoom_mouse(win, key);
	return (key);
}