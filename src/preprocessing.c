
#include "fdf.h"

void	background(char *buffer, int line_bytes, int width, int height)
{
	int pixel;
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pixel = (y * line_bytes) + (x++ * 4);
			buffer[pixel] = 48;
			buffer[pixel + 1] = 38;
			buffer[pixel + 2] = 42;
		}
		y++;
	}
}

void	*get_frame(t_ptr ptr)
{
	void	*frame;
	char	*buffer;
	int 	pixel_bits;
	int		line_bytes;
	int		endian;

	frame = mlx_new_image(ptr.mlx, ptr.width, ptr.height);
	buffer = mlx_get_data_addr(frame, &pixel_bits, &line_bytes, &endian);
	background(buffer, line_bytes, ptr.width, ptr.height);
	return (frame);
}

t_render	preprocessing(t_map map, t_ptr ptr)
{
	t_render	render;

	render.frame = get_frame(ptr);
	render.shift.x = ptr.width / 2;
	render.shift.y = ptr.height / 2;
	render.angle.x = 0;
	render.angle.y = 0;
	render.angle.z = 0;
	return (render);
}