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

#include "../ft-printf/printf.h"
#include "struct.h"

#define	KEY_UP 5
#define	KEY_LEFT 7
#define	KEY_DOWN 4
#define	KEY_RIGHT 6

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

void	draw(t_wind *win);

static void	rotate_x(t_wind *win, float rotate)
{
	win->angl_x += rotate;
	ft_printf("rotate x\n");
}

static void	rotate_y(t_wind *win, float rotate)
{
	win->angl_y += rotate;
	ft_printf("rotate y\n");
}

void	rotate_mouse(t_wind *win, int key)
{
	if (key == KEY_UP)
		rotate_y(win, -0.1);
	else if (key == KEY_LEFT)
		rotate_x(win, -0.1);
	else if (key == KEY_DOWN)
		rotate_y(win, 0.1);
	else if (key == KEY_RIGHT)
		rotate_x(win, 0.1);
	else
		return ;
	draw(win);
}

void	rotate(t_wind *win, int key)
{
	if (key == KEY_W)
		rotate_y(win, -0.05);
	else if (key == KEY_A)
		rotate_x(win, -0.05);
	else if (key == KEY_S)
		rotate_y(win, 0.05);
	else if (key == KEY_D)
		rotate_x(win, 0.05);
	else
		return ;
	draw(win);
}
