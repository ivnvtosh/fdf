#include "fdf.h"

t_frame		parse_frame(t_mlx mlx)
{
	t_frame	frame;
	int		pixel;
	int		line;
	int		endian;

	frame.buffer = mlx_get_data_addr(mlx.screen, &pixel, &line, &endian);
	frame.pixel = pixel;
	frame.line = line;
	frame.endian = endian;
	return (frame);
}
