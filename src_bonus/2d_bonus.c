/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:36:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:36:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static t_point	new_vector_2_here(t_data data, int x, int y)
{
	t_point		vector;
	t_map		map;
	t_render	render;

	map = data.map;
	render = data.render;
	vector.x = render.offset.x + (x - render.center.x) * render.zoom;
	vector.y = render.offset.y + (y - render.center.y) * render.zoom;
	if (data.mode_color == 0)
	{
		vector.rgb.r = get_r(map.color[y][x]);
		vector.rgb.g = get_g(map.color[y][x]);
		vector.rgb.b = get_b(map.color[y][x]);
	}
	if (data.mode_color == 1)
	{
		vector.rgb.r = get_r(map.color_my[y][x]);
		vector.rgb.g = get_g(map.color_my[y][x]);
		vector.rgb.b = get_b(map.color_my[y][x]);
	}
	return (vector);
}

static void	all(t_data data, int x, int y)
{
	t_map		map;
	t_frame		frame;
	t_point		start;
	t_point		end;

	map = data.map;
	frame = data.frame;
	start = new_vector_2_here(data, x, y);
	if (x + 1 < map.size.x)
	{
		end = new_vector_2_here(data, x + 1, y);
		write_line(frame, start, end);
	}
	if (y + 1 < map.size.y)
	{
		end = new_vector_2_here(data, x, y + 1);
		write_line(frame, start, end);
	}
}

void	two_dimensional_space(t_data data, t_map map)
{
	int		x;
	int		y;

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
