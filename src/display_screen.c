/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:22:30 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 19:22:31 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <limits.h>
#include <math.h>

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	background(t_frame frame);
void	two_dimensional_space(t_frame frame, t_render render, int **map);

void	write_pixel(t_frame	frame, int x, int y, int trgb)
{
	unsigned char	*buffer;
	int				pixel;

	buffer = (unsigned char *)frame.buffer;
	pixel = (y * frame.line) + (x * 4);
	buffer[pixel + 0] = get_b(trgb);
	buffer[pixel + 1] = get_g(trgb);
	buffer[pixel + 2] = get_r(trgb);
}

void	write_line(t_frame frame, t_vector2 start, t_vector2 end, int height, int trgb)
{
	t_vector2	step;
	float		stepc;
	float		max;

	if (trgb == 0)
		trgb = 0x111111;
	step.x = end.x - start.x;
	step.y = end.y - start.y;
	stepc = 0xFFA500 - trgb;
	max = ft_max(step.x, step.y);
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (start.x > 0 && start.x < WIDTH && start.y > 0 && start.y < HEIGHT)
			write_pixel(frame, start.x, start.y, trgb);
		start.x += step.x;
		start.y += step.y;
		trgb += stepc * height / 2;
	}
	if (start.x > 0 && start.x < WIDTH && start.y > 0 && start.y < HEIGHT)
		write_pixel(frame, start.x, start.y, trgb);
}

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

	isostart = iso(start);
	isoend = iso(end);
	if (isostart.x > 0 && isostart.x < WIDTH && isostart.y > 0 && isostart.y < HEIGHT)
		write_line(frame, isostart, isoend, height, trgb);
	else if (isoend.x > 0 && isoend.x < WIDTH && isoend.y > 0 && isoend.y < HEIGHT)
		write_line(frame, isostart, isoend, height, trgb);
}

static t_vector2	newvector2(t_render render, t_map map, int x, int y)
{
	t_vector2	new;
	t_vector2	shift;
	t_vector2	center;
	float		zoom;

	shift = render.shift;
	center = render.center;
	zoom = render.zoom;
	new.x = shift.x + (x - center.x - map.height[y][x] / 10) * zoom;
	new.y = shift.y + (y - center.y - map.height[y][x] / 10) * zoom;
	return (new);
}

void	three_dimensional_space(t_frame frame, t_render render, t_map map)
{
	t_vector2	start;
	t_vector2	end;
	int			y;
	int			x;

	y = 0;
	while (map.height[y])
	{
		x = 0;
		while (map.height[y][x] != INT_MIN)
		{
			start = newvector2(render, map, x, y);
			if (map.height[y][x + 1] != INT_MIN)
			{
				end = newvector2(render, map, x + 1, y);
				isometry(frame, start, end, map.height[y][x], map.color[y][x]);
			}
			if (map.height[y + 1])
			{
				end = newvector2(render, map, x, y + 1);
				isometry(frame, start, end, map.height[y][x], map.color[y][x]);
			}
			x++;
		}
		y++;
	}
}

void	display_screen(t_data data)
{
	background(data.mlx.frame);
	if (data.mlx.mode == 2)
		two_dimensional_space(data.mlx.frame, data.render, data.map.color);
	if (data.mlx.mode == 3)
		three_dimensional_space(data.mlx.frame, data.render, data.map);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.frame.screen, 0, 0);
}
