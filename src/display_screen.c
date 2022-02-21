#include "fdf.h"
#include <math.h>

t_vector2	iso(t_vector2 old)
{
	t_vector2	new;

	new.x = (old.x - old.y) * cos(1);
	new.y = (old.x + old.y) / 2 * sin(0.8);
	return (new);
}

void	isometry(t_frame frame, t_vector2 start, t_vector2 end, int trgb)
{
	t_vector2	offset;
	t_vector2	isostart;
	t_vector2	isoend;

	isostart = iso(start);
	isoend = iso(end);
	offset = vector_2_new(WIDTH / 2, HEIGHT / 2);
	isostart = vector_increase(isostart, offset);
	isoend = vector_increase(isoend, offset);
	write_line(frame, isostart, isoend, trgb);
}

static t_vector2	newvector2(t_render render, t_map map, int x, int y)
{
	t_vector2	new;
	t_vector2	center;
	float		zoom;

	center = render.center;
	zoom = ((WIDTH) / map.size.x + (HEIGHT) / map.size.y) / 4;
	new.x = (x - center.x - map.height[y][x] / 8) * zoom;
	new.y = (y - center.y - map.height[y][x] / 8) * zoom;
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
				isometry(frame, start, end, map.color[y][x]);
			}
			if (y + 1 < map.size.y)
			{
				end = newvector2(render, map, x, y + 1);
				isometry(frame, start, end, map.color[y][x]);
			}
			x += 1;
		}
		y += 1;
	}
}

void	display_screen(t_data data, t_mlx mlx)
{
	background(data.frame);
	three_dimensional_space(data.frame, data.render, data.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.screen, 0, 0);
}
