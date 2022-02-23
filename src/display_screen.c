/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:36:04 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 17:36:06 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_vector2	iso(t_vector2 old);

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
	t_vector2	offset;
	float		zoom;

	offset = vector_2_new(WIDTH / 2, HEIGHT / 2);
	center = render.center;
	zoom = ((WIDTH) / map.size.x + (HEIGHT) / map.size.y) / 4;
	new.x = (x - center.x - map.height[y][x] / 2.2) * zoom;
	new.y = (y - center.y - map.height[y][x] / 2.2) * zoom;
	new = iso(new);
	new = vector_increase(new, offset);
	return (new);
}

static void	all(t_data data, int x, int y)
{
	t_map		map;
	t_frame		frame;
	t_vector2	start;
	t_vector2	end;

	map = data.map;
	frame = data.frame;
	start = newvector2(data.render, map, x, y);
	if (x + 1 < map.size.x)
	{
		end = newvector2(data.render, map, x + 1, y);
		write_line(frame, start, end, map.color[y][x]);
	}
	if (y + 1 < map.size.y)
	{
		end = newvector2(data.render, map, x, y + 1);
		write_line(frame, start, end, map.color[y][x]);
	}
}

void	three_dimensional_space(t_data data, t_map map)
{
	int			y;
	int			x;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			all(data, x, y);
			x += 1;
		}
		y += 1;
	}
}

void	display_screen(t_data data, t_mlx mlx)
{
	background(data.frame);
	three_dimensional_space(data, data.map);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.screen, 0, 0);
}
