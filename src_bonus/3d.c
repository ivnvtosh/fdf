#include "fdf.h"
#include <math.h>

#define RADIAN 0.01745329252

t_vector2	iso(t_vector2 old)
{
	t_vector2	new;

	new.x = (old.x - old.y) * cos(1);
	new.y = (old.x + old.y) / 2 * sin(0.8);
	return (new);
}

// static t_vector2	newvector2(t_render render, t_map map, t_vector2 step, t_vector2 basisi, t_vector2 basisj, t_vector2 basisk)
// {
// 	t_vector2	new;
// 	t_vector2	offset;
// 	t_vector2	center;

// 	offset = render.offset;
// 	center = render.center;
// 	new.x = basisi.x * (step.x - center.x) + basisj.x * (step.y - center.y) + basisk.x * (float)map.height[(int)step.y][(int)step.x] * render.height;
// 	new.y = basisi.y * (step.x - center.x) + basisj.y * (step.y - center.y) + basisk.y * (float)map.height[(int)step.y][(int)step.x] * render.height;
// 	// new = iso(new);
// 	new = vector_increase(new, offset);
// 	return (new);
// }

// static t_vector2	vector_get_basis(t_render render)
// {
// 	t_vector2	basis;

// 	basis.y =  render.zoom * cos(render.angle.x * RADIAN) + render.zoom * sin(render.angle.x * RADIAN);
// 	basis.x =  render.zoom * cos(render.angle.y * RADIAN) + render.zoom * sin(render.angle.y * RADIAN);
// 	return (basis);
// }

void	three_dimensional_space(t_frame frame, t_render render, t_map map)
{
	t_vector2	basisi;
	t_vector2	basisj;
	t_vector2	basisk;
	t_vector2	step;
	t_vector2	start;
	t_vector2	end;

	// basis = vector_get_basis(render);
	step.y = 0;
	basisi.x = +1 * render.zoom * cos(render.angle.x * RADIAN);
	basisi.y = -1 * render.zoom * sin(render.angle.x * RADIAN);
	basisj.x = -1 * render.zoom * sin(render.angle.y * RADIAN);
	basisj.y = -1 * render.zoom * cos(render.angle.y * RADIAN);
	basisk.x = -1 * render.zoom * sin(render.angle.x * RADIAN);
	basisk.y = -1 * render.zoom * cos(render.angle.x * RADIAN);
	while (step.y < map.size.y)
	{
		step.x = 0;
		while (step.x < map.size.x)
		{
			// start = newvector2(render, map, step, basisi, basisj, basisk);
			start.x = render.offset.x + basisi.x * (step.x - render.center.x) + basisj.x * (step.y - render.center.y) + basisk.x * (float)map.height[(int)step.y][(int)step.x] * render.height;
			start.y = render.offset.y + basisi.y * (step.x - render.center.x) + basisj.y * (step.y - render.center.y) + basisk.y * (float)map.height[(int)step.y][(int)step.x] * render.height;
			

			if (step.x + 1 < map.size.x)
			{
				end.x = render.offset.x + basisi.x * (step.x + 1 - render.center.x) + basisj.x * (step.y - render.center.y) + basisk.x * (float)map.height[(int)step.y][(int)step.x + 1] * render.height;
				end.y = render.offset.y + basisi.y * (step.x + 1 - render.center.x) + basisj.y * (step.y - render.center.y) + basisk.y * (float)map.height[(int)step.y][(int)step.x + 1] * render.height;
				// end = newvector2(render, map, vector_2_new(step.x, step.y + 1), basisi, basisj, basisk);
				write_line(frame, start, end, map.color[(int)step.y][(int)step.x]);
			}
			if (step.y + 1 < map.size.y)
			{
				end.x = render.offset.x + basisi.x * (step.x - render.center.x) + basisj.x * (step.y + 1 - render.center.y) + basisk.x * (float)map.height[(int)step.y + 1][(int)step.x] * render.height;
				end.y = render.offset.y + basisi.y * (step.x - render.center.x) + basisj.y * (step.y + 1 - render.center.y) + basisk.y * (float)map.height[(int)step.y + 1][(int)step.x] * render.height;
				// end = newvector2(render, map, vector_2_new(step.x + 1, step.y), basisi, basisj, basisk);
				write_line(frame, start, end, map.color[(int)step.y][(int)step.x]);
			}
			step.x += 1;
		}
		step.y += 1;
	}
	printf("%f\n", render.angle.x);
	printf("%f\n", render.angle.y);
	printf("%f\n", render.angle.z);
}
