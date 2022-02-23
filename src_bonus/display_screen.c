#include "fdf.h"

void	two_dimensional_space(t_data data, t_map map);
void	three_dimensional_space(t_data data, t_render render, t_map map);

void	display_screen(t_data data, t_mlx mlx)
{
	background(data.frame);
	if (data.mode == 2)
		two_dimensional_space(data, data.map);
	if (data.mode == 3)
		three_dimensional_space(data, data.render, data.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.screen, 0, 0);
}
