/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
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

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}	t_line;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

void	background(t_mlx mlx);

void	write_pixel(t_mlx mlx, t_point point)
{
	t_frame	frame;
	int		pixel;

	frame = mlx.frame;
	pixel = ((int)point.y * frame.line) + ((int)point.x * 4);
	frame.buffer[pixel] = 120;
	frame.buffer[pixel + 1] = 120;
	frame.buffer[pixel + 2] = 120;
}

void	write_line(t_mlx mlx, t_point start, t_point end)
{
	t_point	step;
	int		max;

	step.x = end.x - start.x;
	step.y = end.y - start.y;
	max = ft_max(step.x, step.y);
	step.x /= max;
	step.y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (start.x > 0 && start.x < mlx.width && start.y > 0 && start.y < mlx.height)
			write_pixel(mlx, start);
		start.x += step.x;
		start.y += step.y;
	}
}

void	display_screen(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.frame.screen, 0, 0);
}

void	draw(t_data data)
{
	t_line	line;
	t_xyz	shift;
	t_xyz	center;
	int		**map;
	int		y;
	int		x;

	map = data.map.height;
	shift = data.render.shift;
	center = data.render.center;
	background(data.mlx);

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != INT_MIN)
		{
			line.start.x = shift.x + data.render.zoom * (x - center.x    );
			line.start.y = shift.y + data.render.zoom * (y - center.y    );
			if (map[y][x + 1] != INT_MIN)
			{
				line.end.x = shift.x + data.render.zoom * (x - center.x + 1);
				line.end.y = shift.y + data.render.zoom * (y - center.y    );
				write_line(data.mlx, line.start, line.end);
			}
			if (map[y + 1])
			{
				line.end.x = shift.x + data.render.zoom * (x - center.x    );
				line.end.y = shift.y + data.render.zoom * (y - center.y + 1);
				write_line(data.mlx, line.start, line.end);
			}
			x++;
		}
		y++;
	}
	display_screen(data.mlx);
}
