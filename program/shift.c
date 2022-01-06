/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:04:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:04:37 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift(t_wind *win, int key)
{
	if (key == KEY_UP)
		win->offset_y -= 10;
	else if (key == KEY_LEFT)
		win->offset_x -= 10;
	else if (key == KEY_DOWN)
		win->offset_y += 10;
	else if (key == KEY_RIGHT)
		win->offset_x += 10;
	else
		return ;
	draw(win);
}
