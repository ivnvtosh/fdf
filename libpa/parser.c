#include "fdf.h"

t_map	parse_map(char *path);

t_render	parse_var(t_vector2 size)
{
	t_render	render;

	render.offset.x = WIDTH / 2;
	render.offset.y = HEIGHT / 2;
	render.angle.x = 0;
	render.angle.y = 0;
	render.angle.z = 0;
	// render.center = get_center(map.height);
	render.zoom = 16;
	return (render);
}

t_mlx	parse_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FDF");
	// mlx.frame = get_frame(mlx);
	return (mlx);
}

t_data	parser(char *path)
{
	t_data	data;

	data.map = parse_map(path);
	data.render = parse_var(map.size)
	data.mode = 2;
	data.mlx = parse_mlx();
	data.frame = parse_frame(data.mlx);
	return (data);
}
