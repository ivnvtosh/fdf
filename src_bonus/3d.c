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

static t_point new_vector_2_here(t_data data, t_basis basis, int x, int y)
{
	t_point		vector;
	t_map		map;
	t_render	render;

	map = data.map;
	render = data.render;
	vector.x = render.offset.x + basis.i.x * (x - render.center.x) + basis.j.x * (y - render.center.y) + basis.k.x * (float)map.height[y][x] * render.height;
	vector.y = render.offset.y + basis.i.y * (x - render.center.x) + basis.j.y * (y - render.center.y) + basis.k.y * (float)map.height[y][x] * render.height;
	if (data.mode_color == 0)
	{
		vector.rgb.r =  get_r(map.color[y][x]);
		vector.rgb.g =  get_g(map.color[y][x]);
		vector.rgb.b =  get_b(map.color[y][x]);
	}
	if (data.mode_color == 1)
	{
		vector.rgb.r =  get_r(map.color_my[y][x]);
		vector.rgb.g =  get_g(map.color_my[y][x]);
		vector.rgb.b =  get_b(map.color_my[y][x]);
	}
	return (vector);
}

static void	all(t_data data, t_vector2 step, t_basis basis)
{
	t_map		map;
	t_frame		frame;
	t_point		start;
	t_point		end;

	map = data.map;
	frame = data.frame;
	start = new_vector_2_here(data, basis, (int)step.x, (int)step.y);
	if (step.x + 1 < map.size.x)
	{
		end = new_vector_2_here(data, basis, (int)step.x + 1, (int)step.y);
		write_line(frame, start, end);
	}
	if (step.y + 1 < map.size.y)
	{
		end = new_vector_2_here(data, basis, (int)step.x, (int)step.y + 1);
		write_line(frame, start, end);
	}
}

void	three_dimensional_space(t_data data, t_render render, t_map map)
{
	t_basis		basis;
	t_vector2	step;

	basis = vector_get_basis(render);
	step.y = 0;
	while (step.y < map.size.y)
	{
		step.x = 0;
		while (step.x < map.size.x)
		{
			all(data, step, basis);
			step.x += 1;
		}
		step.y += 1;
	}
}
