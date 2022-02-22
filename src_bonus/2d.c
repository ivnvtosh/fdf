#include "fdf.h"

void	two_dimensional_space(t_frame frame, t_render render, t_map map)
{
	t_point	start;
	t_point	end;
	int		x;
	int		y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			start.x = render.offset.x + (x - render.center.x) * render.zoom;
			start.y = render.offset.y + (y - render.center.y) * render.zoom;
			start.trgb = map.color[y][x];
			if (x + 1 < map.size.x)
			{
				end.x = render.offset.x + (x - render.center.x + 1) * render.zoom;
				end.y = render.offset.y + (y - render.center.y) * render.zoom;
				end.trgb = map.color[y][x + 1];
				write_line(frame, start, end);
			}
			if (y + 1 < map.size.y)
			{
				end.x = render.offset.x + (x - render.center.x) * render.zoom;
				end.y = render.offset.y + (y - render.center.y + 1) * render.zoom;
				end.trgb = map.color[y + 1][x];
				write_line(frame, start, end);
			}
			x += 1;
		}
		y += 1;
	}
}
