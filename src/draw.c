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
#include "mlx.h"

void	background(t_mlx mlx);

static int	ft_max(float step_x, float step_y)
{
	if (step_x < 0)
		step_x *= -1;
	if (step_y < 0)
		step_y *= -1;
	if (step_x > step_y)
		return (step_x);
	return (step_y);
}

void	write_pixel(t_mlx mlx, int x, int y)
{
	t_frame	frame;
	int		pixel;

	frame = mlx.frame;
	pixel = (y * frame.line) + ((x++) * 4);
	frame.buffer[pixel] = 120;
	frame.buffer[pixel + 1] = 120;
	frame.buffer[pixel + 2] = 120;
}

void	write_line(t_mlx mlx, float x, float y, float x1, float y1)
{
	float	step_x;
	float	step_y;
	int		max;

	step_x = x1 - x;
	step_y = y1 - y;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x > 0 && x < 1220 && y > 0 && y < 700)
			write_pixel(mlx, x, y);
		x += step_x;
		y += step_y;
	}
}

void	display_screen(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.frame.screen, 0, 0);
}

void	draw(t_data data)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	background(data.mlx);
	x1 = data.render.zoom;
	y1 = data.render.zoom;
	x2 = data.render.zoom;
	y2 = data.render.zoom;
	write_line(data.mlx, x1, y1 * 2, x2, y2);

	display_screen(data.mlx);
}
