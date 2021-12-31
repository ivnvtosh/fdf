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
void	draw(t_wind *win);

void	shift_x(t_wind *win, int shift)
{
	ft_printf("shift_x\n");
	
	win->offset_x += shift;
}

void	shift_y(t_wind *win, int shift)
{
	ft_printf("shift_y\n");
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