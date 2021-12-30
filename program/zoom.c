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