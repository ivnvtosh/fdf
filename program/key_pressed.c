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

#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "keys.h"
#include <stdlib.h>

void	rotate(t_wind *win, int key);
void	shift(t_wind *win, int key);
void	shutdown(t_wind *win, int key);
void	zoom(t_wind *win, int key);
void	draw(t_wind *win);

static void	rotate_x(t_wind *win, float rotate)
{
	ft_printf("rotate_x\n");
	win->angl_x += rotate;
	win->angl_y += rotate;
}

static void	rotate_y(t_wind *win, float rotate)
{
	ft_printf("rotate_y\n");
	win->angl_x += rotate;
	win->angl_y += rotate;
}

void	rotate_ox(t_wind *win, int key)
{
	if (key == 12)
		rotate_y(win, -0.05);
	else if (key == 14)
		rotate_x(win, 0.05);
	else
		return ;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw(win);
}

int	key_pressed(int key, t_wind *win)
{
	// key = mlx_do_key_autorepeaton(win->mlx_ptr);
	// ft_printf("%d", key);
	rotate_ox(win, key);
	rotate(win, key);
	shift(win, key);
	shutdown(win, key);
	zoom(win, key);
	return (0);
}