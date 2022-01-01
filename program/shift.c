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

#include "struct.h"
#include "../ft-printf/printf.h"

#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_DOWN 125
#define KEY_RIGHT 124

void	draw(t_wind *win);

void	shift_x(t_wind *win, int shift)
{
	win->offset_x += shift;
	ft_printf("shift_x\n");
}

void	shift_y(t_wind *win, int shift)
{
	win->offset_y += shift;
	ft_printf("shift_y\n");
}

void	shift(t_wind *win, int key)
{
	if (key == KEY_UP)
		shift_y(win, -10);
	else if (key == KEY_LEFT)
		shift_x(win, -10);
	else if (key == KEY_DOWN)
		shift_y(win, 10);
	else if (key == KEY_RIGHT)
		shift_x(win, 10);
	else
		return ;
	draw(win);
}
