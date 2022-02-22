#include "fdf.h"
#include <math.h>

#define RADIAN 0.01745329252

typedef struct s_basis
{
	t_vector2	i;
	t_vector2	j;
	t_vector2	k;
}	t_basis;

static t_basis	vector_get_basis(t_render render)
{
	t_basis	basis;

	basis.i.x = +1 * render.zoom * cos(render.angle.x * RADIAN);
	basis.i.y = -1 * render.zoom * sin(render.angle.x * RADIAN);
	basis.j.x = -1 * render.zoom * sin(render.angle.y * RADIAN);
	basis.j.y = -1 * render.zoom * cos(render.angle.y * RADIAN);
	basis.k.x = -1 * render.zoom * sin(render.angle.x * RADIAN);
	basis.k.y = -1 * render.zoom * cos(render.angle.x * RADIAN);
	return (basis);
}

void	three_dimensional_space(t_frame frame, t_render render, t_map map)
{
	t_basis		basis;
	t_vector2	step;
	t_point		start;
	t_point		end;

	basis = vector_get_basis(render);
	step.y = 0;
	while (step.y < map.size.y)
	{
		step.x = 0;
		while (step.x < map.size.x)
		{
			start.x = render.offset.x + basis.i.x * (step.x - render.center.x) + basis.j.x * (step.y - render.center.y) + basis.k.x * (float)map.height[(int)step.y][(int)step.x] * render.height;
			start.y = render.offset.y + basis.i.y * (step.x - render.center.x) + basis.j.y * (step.y - render.center.y) + basis.k.y * (float)map.height[(int)step.y][(int)step.x] * render.height;
			start.height = map.height[(int)step.y][(int)step.x];
			start.trgb = map.color[(int)step.y][(int)step.x];
			if (step.x + 1 < map.size.x)
			{
				end.x = render.offset.x + basis.i.x * (step.x + 1 - render.center.x) + basis.j.x * (step.y - render.center.y) + basis.k.x * (float)map.height[(int)step.y][(int)step.x + 1] * render.height;
				end.y = render.offset.y + basis.i.y * (step.x + 1 - render.center.x) + basis.j.y * (step.y - render.center.y) + basis.k.y * (float)map.height[(int)step.y][(int)step.x + 1] * render.height;
				end.height = map.height[(int)step.y][(int)step.x + 1];
				end.trgb = map.color[(int)step.y][(int)step.x + 1];
				write_line(frame, start, end);
			}
			if (step.y + 1 < map.size.y)
			{
				end.x = render.offset.x + basis.i.x * (step.x - render.center.x) + basis.j.x * (step.y + 1 - render.center.y) + basis.k.x * (float)map.height[(int)step.y + 1][(int)step.x] * render.height;
				end.y = render.offset.y + basis.i.y * (step.x - render.center.x) + basis.j.y * (step.y + 1 - render.center.y) + basis.k.y * (float)map.height[(int)step.y + 1][(int)step.x] * render.height;
				end.height = map.height[(int)step.y + 1][(int)step.x];
				end.trgb = map.color[(int)step.y + 1][(int)step.x];
				write_line(frame, start, end);
			}
			step.x += 1;
		}
		step.y += 1;
	}
}
