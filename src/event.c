#include "fdf.h"

int		key_pressed(int key, t_data *data);
int		mouse_released(int key, int x, int y, t_data *data);
int		mouse_pressed(int key, int x, int y, t_data *data);

void	event(t_data *data, t_mlx mlx)
{
	mlx_hook(mlx.win, 2, 0, key_pressed, data);
	mlx_hook(mlx.win, 4, 0, mouse_pressed, data);
	mlx_hook(mlx.win, 5, 0, mouse_released, data);
	mlx_hook(mlx.win, 17, 0, terminate, data);
	mlx_loop(mlx.mlx);
}
