#include "fdf.h"

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
