/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:04:16 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:04:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_wind *win, float rotate)
{
	win->angl_z += rotate;
}

static void	rotate_y(t_wind *win, float rotate)
{
	win->angl_z += rotate;
}

void	rotate_z(t_wind *win, int key)
{
	if (key == 12)
		rotate_y(win, 5);
	else if (key == 14)
		rotate_x(win, -5);
	else
		return ;
	draw(win);
}

int	key_pressed(int key, t_wind *win)
{
	rotate_z(win, key);
	rotate(win, key);
	shift(win, key);
	shutdown(win, key);
	zoom(win, key);
	if (key == 48)
	{
		win->draw_panel *= -1;
		draw(win);
	}
	if (key == 49)
	{
		win->offset_x = 610;
		win->offset_y = 350;
		win->angl_x = 0;
		win->angl_y = -90;
		win->angl_z = 0;
		win->zoom = 800 / (win->centre_x * 2 + win->centre_y * 2) + 1;
		draw(win);
	}
	return (0);
}
