/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:04:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:04:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include <stdio.h>

#include "struct.h"
void	status_panel(t_wind *win);
void	draw_plane(t_wind *win);

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

void	draw_line_x(t_wind *win, float x1, float y1, float x2, float y2)
{
	float	step_x;
	float	step_y;
	int		color;
	int		max;
	int		z1;
	int		z2;

	z1 = win->map[(int)y1][(int)x1][0] * win->zoom / win->zoom;
	z2 = win->map[(int)y2][(int)x2][0] * win->zoom / win->zoom;
	x1 *= win->zoom;
	x2 *= win->zoom;
	y1 *= win->zoom;
	y2 *= win->zoom;
	x1 = (x1 - y1) * cos(1);
	y1 = (x1 + y1) * sin(1) - z1;
	x2 = (x2 - y2) * cos(1);
	y2 = (x2 + y2) * sin(1) - z2;
	x1 += x1 * cos(win->angl_x);
	y1 += y1 * sin(win->angl_y) - z1;
	x2 += x2 * cos(win->angl_x);
	y2 += y2 * sin(win->angl_y) - z2;
	step_x = x2 - x1;
	step_y = y2 - y1;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	if (z1 || z2)
		color = 0xDD9922;
	else
		color = win->color;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1 + win->offset_x, y1 + win->offset_y, color);
		x1 += step_x;
		y1 += step_y;
		// color += z1;
	}
}

void	draw(t_wind *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image, 0, 0);
	draw_plane(win);
	status_panel(win);
}
