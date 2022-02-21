#include "fdf.h"

static t_vector2	get_offset(void)
{
	t_vector2	offset;

	offset.x = WIDTH / 2;
	offset.y = HEIGHT / 2;
	return (offset);
}

static t_vector3	get_angle(void)
{
	t_vector3	angle;

	angle.x = 0;
	angle.y = 135;
	angle.z = 0;
	return (angle);
}

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

	render.offset = get_offset();
	render.angle = get_angle();
	render.center = get_center(size);
	render.height = 0.1;
	render.zoom = ((WIDTH) / size.x + (HEIGHT) / size.y) / 4;
	return (render);
}
