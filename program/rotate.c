/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:04:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:04:59 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_mouse(t_wind *win, int key)
{
	if (key == KEY_UP)
		win->angl_y -= 5;
	else if (key == KEY_LEFT)
		win->angl_x -= 5;
	else if (key == KEY_DOWN)
		win->angl_y += 5;
	else if (key == KEY_RIGHT)
		win->angl_x += 5;
	else
		return ;
	draw(win);
}

void	rotate(t_wind *win, int key)
{
	if (key == KEY_W)
		win->angl_y -= 5;
	else if (key == KEY_A)
		win->angl_x -= 5;
	else if (key == KEY_S)
		win->angl_y += 5;
	else if (key == KEY_D)
		win->angl_x += 5;
	else
		return ;
	draw(win);
}
