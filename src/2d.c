
#include "fdf.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <limits.h>

int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

static int	on_the_screen(t_vector2	vector)
{
	if (!(vector.x > 0 && vector.x < WIDTH))
		return (0);
	if (!(vector.y > 0 && vector.y < HEIGHT))
		return (0);
	return (1);
}

static void	write_pixel(t_frame	frame, int x, int y, int trgb)
{
	unsigned char	*buffer;
	int				pixel;

	buffer = (unsigned char *)frame.buffer;
	pixel = (y * frame.line) + (x * 4);
	buffer[pixel + 0] = get_b(trgb);
	buffer[pixel + 1] = get_g(trgb);
	buffer[pixel + 2] = get_r(trgb);
}

static void	write_line(t_frame frame, t_vector2 start, t_vector2 end, int trgb)
{
	t_vector2	step;
	float		max;

	if (trgb == 0)
		trgb = 0x111111;
	step.x = end.x - start.x;
	step.y = end.y - start.y;
	max = ft_max(step.x, step.y);
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (on_the_screen(start))
			write_pixel(frame, start.x, start.y, trgb);
		start.x += step.x;
		start.y += step.y;
	}
	if (on_the_screen(start))
		write_pixel(frame, start.x, start.y, trgb);
}

static t_vector2	new_vector2(t_render render, int x, int y)
{
	t_vector2	new;
	t_vector2	shift;
	t_vector2	center;
	float		zoom;

	shift = render.shift;
	center = render.center;
	zoom = render.zoom;
	new.x = shift.x + (x - center.x) * zoom;
	new.y = shift.y + (y - center.y) * zoom;
	return (new);
}

void	two_dimensional_space(t_frame frame, t_render render, int **map)
{
	t_vector2	start;
	t_vector2	end;
	int			y;
	int			x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != INT_MIN)
		{
			start.x = render.shift.x + (x - render.center.x) * render.zoom;
			start.y = render.shift.y + (y - render.center.y) * render.zoom;
			if (map[y][x + 1] != INT_MIN)
			{
				end.x = render.shift.x + (x - render.center.x + 1) * render.zoom;
				end.y = render.shift.y + (y - render.center.y) * render.zoom;
				if (on_the_screen(start) || on_the_screen(end))
					write_line(frame, start, end, map[y][x]);
			}
			if (map[y + 1])
			{
				end.x = render.shift.x + (x - render.center.x) * render.zoom;
				end.y = render.shift.y + (y - render.center.y + 1) * render.zoom;
				if (on_the_screen(start) || on_the_screen(end))
					write_line(frame, start, end, map[y][x]);
			}
			x++;
		}
		y++;
	}
}
