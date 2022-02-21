#include "fdf.h"
#include <math.h>

// static t_vector2	new_vector2(t_render render, int x, int y)
// {
// 	t_vector2	new;
// 	t_vector2	offset;
// 	t_vector2	center;
// 	float		zoom;

// 	offset = render.offset;
// 	center = render.center;
// 	zoom = render.zoom;
// 	new.x = offset.x + (x - center.x) * zoom;
// 	new.y = offset.y + (y - center.y) * zoom;
// 	return (new);
// }

t_vector2	iso(t_vector2 old)
{
	t_vector2	new;

	new.x = (old.x - old.y) * cos(1);
	new.y = (old.x + old.y) / 2 * sin(0.8);
	return (new);
}

void	isometry(t_frame frame, t_vector2 start, t_vector2 end, int height, int trgb)
{
	t_vector2	isostart;
	t_vector2	isoend;

	(void)height;
	isostart = iso(start);
	isoend = iso(end);
	if (isostart.x > 0 && isostart.x < WIDTH && isostart.y > 0 && isostart.y < HEIGHT)
		write_line(frame, isostart, isoend, trgb);
	else if (isoend.x > 0 && isoend.x < WIDTH && isoend.y > 0 && isoend.y < HEIGHT)
		write_line(frame, isostart, isoend, trgb);
}

static t_vector2	newvector2(t_render render, t_map map, int x, int y)
{
	t_vector2	new;
	t_vector2	offset;
	t_vector2	center;
	float		zoom;

	offset = render.offset;
	center = render.center;
	zoom = render.zoom;
	new.x = offset.x + (x - center.x - map.height[y][x] / 10) * zoom;
	new.y = offset.y + (y - center.y - map.height[y][x] / 10) * zoom;
	return (new);
}

void	three_dimensional_space(t_frame frame, t_render render, t_map map)
{
	t_vector2	start;
	t_vector2	end;
	int			y;
	int			x;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			start = newvector2(render, map, x, y);
			if (x + 1 < map.size.x)
			{
				end = newvector2(render, map, x + 1, y);
				isometry(frame, start, end, map.height[y][x], map.color[y][x]);
			}
			if (y + 1 < map.size.y)
			{
				end = newvector2(render, map, x, y + 1);
				isometry(frame, start, end, map.height[y][x], map.color[y][x]);
			}
			x += 1;
		}
		y += 1;
	}
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
	if (data.mode == 3)
		three_dimensional_space(data.frame, data.render, data.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.screen, 0, 0);
}
