#include "fdf.h"

t_mlx	parse_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FDF");
	mlx.screen = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	return (mlx);
}
