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

int	key_pressed(int key, t_wind *win)
{
	// key = mlx_do_key_autorepeaton(win->mlx_ptr);
	rotate(win, key);
	shift(win, key);
	shutdown(win, key);
	zoom(win, key);
	return (0);
}