/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:09:30 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 20:09:32 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	write_pixel(t_frame	frame, t_point vector)
{
	unsigned char	*buffer;
	int				pixel;

	if (pixel_on_the_screen(vector))
		return ;
	buffer = (unsigned char *)frame.buffer;
	pixel = ((int)vector.y * frame.line) + ((int)vector.x * 4);
	buffer[pixel + 0] = vector.rgb.b;
	buffer[pixel + 1] = vector.rgb.g;
	buffer[pixel + 2] = vector.rgb.r;
}

int	get_i(t_point start, t_point end, t_point step)
{
	int	i;

	i = 0;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		start = vector_increase(start, step);
		i += 1;
	}
	return (i);
}

t_rgb	get_rgb(t_point start, t_point end, int i)
{
	t_rgb	step_rgb;

	step_rgb.r = end.rgb.r - start.rgb.r;
	step_rgb.g = end.rgb.g - start.rgb.g;
	step_rgb.b = end.rgb.b - start.rgb.b;
	step_rgb.r /= i;
	step_rgb.g /= i;
	step_rgb.b /= i;
	return (step_rgb);
}

void	write_line(t_frame frame, t_point start, t_point end)
{
	t_rgb	step_rgb;
	t_point	step;
	int		i;

	if (line_on_the_screen(start, end))
		return ;
	step = vector_reduce(end, start);
	step = vector_divide(step, ft_max(step.x, step.y));
	i = get_i(start, end, step);
	write_pixel(frame, start);
	if (i == 0)
		return ;
	step_rgb = get_rgb(start, end, i);
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		write_pixel(frame, start);
		start = vector_increase(start, step);
		start.rgb.r += step_rgb.r;
		start.rgb.g += step_rgb.g;
		start.rgb.b += step_rgb.b;
	}
}
