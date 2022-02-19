#include "fdf.h"

t_map		parse_map(char *path);
t_render	parse_var(t_vector2 size);
t_mlx		parse_mlx(void);
t_frame		parse_frame(t_mlx mlx);

t_data	parser(char *path)
{
	t_data	data;

	data.map = parse_map(path);
	data.render = parse_var(data.map.size);
	data.mode = 2;
	data.mlx = parse_mlx();
	data.frame = parse_frame(data.mlx);
	return (data);
}
