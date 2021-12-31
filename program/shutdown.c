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