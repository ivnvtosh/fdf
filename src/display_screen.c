#include "fdf.h"

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

static int	on_the_screen(t_vector2	vector)
{
	if (!(vector.x > 0 && vector.x < WIDTH))
		return (0);
	if (!(vector.y > 0 && vector.y < HEIGHT))
		return (0);
	return (1);
}


static void	write_pixel(t_frame	frame, t_vector2 vector, int trgb)
{
	unsigned char	*buffer;
	int				pixel;

	if (!on_the_screen(vector))
		return ;
	buffer = (unsigned char *)frame.buffer;
	pixel = (vector.y * frame.line) + (vector.x * 4);
	buffer[pixel + 0] = get_b(trgb);
	buffer[pixel + 1] = get_g(trgb);
	buffer[pixel + 2] = get_r(trgb);
}

t_vector2	vector_divide(t_vector2 vector, int divider)
{
	vector.x /= divider;
	vector.y /= divider;
	return (vector);
}

t_vector2	vector_reduce(t_vector2 vector, t_vector2 reduce)
{
	vector.x -= reduce.x;
	vector.y -= reduce.y;
	return (vector);
}

t_vector2	vector_increase(t_vector2 vector, t_vector2 increase)
{
	vector.x += increase.x;
	vector.y += increase.y;
	return (vector);
}

static void	write_line(t_frame frame, t_vector2 start, t_vector2 end, int trgb)
{
	t_vector2	step;
	float		max;

	if (!on_the_screen(start) && !on_the_screen(end))
		return ;
	step = vector_reduce(end, start);
	max = ft_max(step.x, step.y);
	step = vector_divide(step, max);
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		write_pixel(frame, start, trgb);
		start = vector_increase(start, step);
	}
	write_pixel(frame, start, trgb);
}

void	two_dimensional_space(t_frame frame, t_render render, t_map map)
{
	t_vector2	start;
	t_vector2	end;
	int			x;
	int			y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			start.x = render.offset.x + (x - render.center.x) * render.zoom;
			start.y = render.offset.y + (y - render.center.y) * render.zoom;
			if (x + 1 < map.size.x)
			{
				end.x = render.offset.x + (x - render.center.x + 1) * render.zoom;
				end.y = render.offset.y + (y - render.center.y) * render.zoom;
				write_line(frame, start, end, map.color[y][x]);
			}
			if (y + 1 < map.size.y)
			{
				end.x = render.offset.x + (x - render.center.x) * render.zoom;
				end.y = render.offset.y + (y - render.center.y + 1) * render.zoom;
				write_line(frame, start, end, map.color[y][x]);
			}
			x += 1;
		}
		y += 1;
	}
}

void	display_screen(t_data data, t_mlx mlx)
{
	background(data.frame);
	if (data.mode == 2)
		two_dimensional_space(data.frame, data.render, data.map);
	// if (data.mode == 3)
	// 	three_dimensional_space(data.frame, data.render, data.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.screen, 0, 0);
}
