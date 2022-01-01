/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:04:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:04:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-printf/printf.h"
#include "struct.h"
#include "../minilibx_macos/mlx.h"
#include <math.h>

#define	UP 5
#define	LEFT 7
#define	DOWN 4
#define	RIGHT 6

void	draw(t_wind *win);
void	rotate_mouse(t_wind *win, int key);
void	zoom_mouse(t_wind *win, int key);

int	mouse_pressed_lol(int x, int y, t_wind *win)
{
	static int	x1;
	static int	y1;

	if (y - y1 > 100)
		y1 = y;
	if (y1 - y > 100)
		y1 = y;
	if (y - y1 > 0)
		win->angl_y += (y - y1) * 0.01;
	else
		win->angl_y -= (y1 - y) * 0.01;
	if (x - x1 > 100)
		x1 = x;
	if (x1 - x > 100)
		x1 = x;
	if (x - x1 > 0)
		win->angl_x += (x - x1) * 0.01;
	else
		win->angl_x -= (x1 - x) * 0.01;
	y1 = y;
	x1 = x;
	ft_printf("angle\n");
	draw(win);
	return (x + y);
}

int	mouse_pressed_shift(int x, int y, t_wind *win)
{
	static int	x1;
	static int	y1;

	if (y - y1 > 50)
		y1 = y;
	if (y1 - y > 50)
		y1 = y;
	if (x - x1 > 50)
		x1 = x;
	if (x1 - x > 50)
		x1 = x;
	if (y - y1 > 0)
	{
		win->offset_y += (y - y1);
		win->offset_x += (x - x1);
	}
	else
	{
		win->offset_y -= (y1 - y) ;
		win->offset_x -= (x1 - x);
	}
	// if (x - x1 > 0)
	// 	win->offset_x += (x - x1);
	// else
	// 	win->offset_x -= (x1 - x);
	y1 = y;
	x1 = x;
	ft_printf("shift\n");
	draw(win);
	return (x + y);
}



int	mouse_pressed(int key, int x, int y, t_wind *win)
{
	if (key == 1)
	{
		mlx_hook(win->win_ptr, 6, 0, mouse_pressed_shift, win);
		// mlx_hook(win->win_ptr, 6, 0, mouse_pressed_lol, win);
		ft_printf("pressed the key %d *left click* x-%d y-%d \n", key, x, y);
	}
	else if (key == 2)
	{
		mlx_hook(win->win_ptr, 6, 0, mouse_pressed_lol, win);
		ft_printf("pressed the key %d *right click* x-%d y-%d \n", key, x, y);
	}
	// rotate_mouse(win, key);
	zoom_mouse(win, key);
	return (0);
}
