#include "fdf.h"

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
}	t_rgb;

void	write_pixel(t_frame	frame, t_point vector)
{
	unsigned char	*buffer;
	int				pixel;

	if (pixel_on_the_screen(vector))
		return ;
	buffer = (unsigned char *)frame.buffer;
	pixel = ((int)vector.y * frame.line) + ((int)vector.x * 4);
	buffer[pixel + 0] = get_b(vector.trgb);
	buffer[pixel + 1] = get_g(vector.trgb);
	buffer[pixel + 2] = get_r(vector.trgb);
}

int	get_i(t_point start, t_point end, t_point step)
{
	int	i;

	i = 0;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		start = vector_increase(start, step);
		i += 1;
	}
	return (i);
}

void	write_line(t_frame frame, t_point start, t_point end)
{
	t_point	step;
	t_rgb	step_rgb;
	t_rgb	rgb;
	int		trgb;
	int		i;

	if (line_on_the_screen(start, end))
		return ;
	trgb = start.trgb;
	step_rgb.r = get_r(end.trgb) - get_r(start.trgb);
	step_rgb.g = get_g(end.trgb) - get_g(start.trgb);
	step_rgb.b = get_b(end.trgb) - get_b(start.trgb);
	rgb.r = get_r(start.trgb);
	rgb.g = get_g(start.trgb);
	rgb.b = get_b(start.trgb);
	step = vector_reduce(end, start);
	step = vector_divide(step, ft_max(step.x, step.y));
	i = get_i(start, end, step);
	write_pixel(frame, start);
	if (i == 0)
		return ;
	step_rgb.r /= i;
	step_rgb.g /= i;
	step_rgb.b /= i;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		write_pixel(frame, start);
		start = vector_increase(start, step);
		rgb.r += step_rgb.r;
		rgb.g += step_rgb.g;
		rgb.b += step_rgb.b;
		((unsigned char *)&trgb)[2] = (int)rgb.r;
		((unsigned char *)&trgb)[1] = (int)rgb.g;
		((unsigned char *)&trgb)[0] = (int)rgb.b;
		start.trgb = trgb;
	}
}
