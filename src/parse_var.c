#include "fdf.h"

static t_vector2	get_center(t_vector2 size)
{
	t_vector2	center;

	center.x = size.x / 2;
	center.y = size.y / 2;
	return (center);
}

t_render	parse_var(t_vector2 size)
{
	t_render	render;

	render.center = get_center(size);
	return (render);
}
