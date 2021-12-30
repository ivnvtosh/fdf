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

static void	rotate_x(t_wind *win, float rotate)
{
	ft_printf("rotate_x\n");
	win->angl_x += rotate;
	// win->offset_x += 20;
}

static void	rotate_y(t_wind *win, float rotate)
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