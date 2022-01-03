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

int	mouse_pressed_lol(int x1, int y1, t_wind *win)
{
	int	x;
	int	y;

	x = win->mouse_x;
	y = win->mouse_y;
	if (y - y1 > 0)
		win->angl_y += (y1 - y) * 0.1;
	else
		win->angl_y -= (y - y1) * 0.1;
	if (x - x1 > 0)
		win->angl_x -= (x1 - x) * 0.1;
	else
		win->angl_x += (x - x1) * 0.1;
	win->mouse_x = x1;
	win->mouse_y = y1;
	ft_printf("angle\n");
	draw(win);
	return (x + y);
}

int	mouse_pressed_shift(int x1, int y1, t_wind *win)
{
	int	x;
	int	y;

	x = win->mouse_x;
	y = win->mouse_y;
	if (y - y1 > 0)
	{
		win->offset_y -= (y - y1);
		win->offset_x -= (x - x1);
	}
	else
	{
		win->offset_y += (y1 - y);
		win->offset_x += (x1 - x);
	}
	win->mouse_x = x1;
	win->mouse_y = y1;
	ft_printf("shift\n");
	draw(win);
	return (x + y);
}



int	mouse_pressed(int key, int x, int y, t_wind *win)
{
	if (key == 1)
	{
		win->mouse_x = x;
		win->mouse_y = y;
		mlx_hook(win->win_ptr, 6, 0, mouse_pressed_shift, win);
		// mlx_hook(win->win_ptr, 6, 0, mouse_pressed_lol, win);
		ft_printf("pressed the key %d *left click* x-%d y-%d \n", key, x, y);
	}
	else if (key == 2)
	{
		win->mouse_x = x;
		win->mouse_y = y;
		mlx_hook(win->win_ptr, 6, 0, mouse_pressed_lol, win);
		ft_printf("pressed the key %d *right click* x-%d y-%d \n", key, x, y);
	}
	// rotate_mouse(win, key);
	zoom_mouse(win, key);
	return (0);
}
