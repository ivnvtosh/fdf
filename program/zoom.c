/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:18 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:05:20 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_mouse(t_wind *win, int key)
{
	if (key == MOUSE_UP)
		win->zoom += win->zoom / 20;
	else if (key == MOUSE_DOWN)
		win->zoom -= win->zoom / 20;
	else
		return ;
	draw(win);
}

void	zoom(t_wind *win, int key)
{
	if (key == KEY_PLUS)
		win->zoom += win->zoom / 20;
	else if (key == KEY_MINUS )
		win->zoom -= win->zoom / 20;
	else
		return ;
	draw(win);
}
