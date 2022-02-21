#include "fdf.h"

void	write_pixel(t_frame	frame, t_vector2 vector, int trgb);
void	write_line(t_frame frame, t_vector2 start, t_vector2 end, int trgb);

void	write_pixel(t_frame	frame, t_vector2 vector, int trgb)
{
	unsigned char	*buffer;
	int				pixel;

	if (pixel_on_the_screen(vector))
		return ;
	buffer = (unsigned char *)frame.buffer;
	pixel = ((int)vector.y * frame.line) + ((int)vector.x * 4);
	buffer[pixel + 0] = get_b(trgb);
	buffer[pixel + 1] = get_g(trgb);
	buffer[pixel + 2] = get_r(trgb);
}

void	write_line(t_frame frame, t_vector2 start, t_vector2 end, int trgb)
{
	t_vector2	step;
	float		max;

	if (line_on_the_screen(start, end))
		return ;
	step = vector_reduce(end, start);
	max = ft_max(step.x, step.y);
	step = vector_divide(step, max);
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		write_pixel(frame, start, trgb);
		start = vector_increase(start, step);
	}
}
