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

#include "../ft-printf/printf.h"
#include "struct.h"

#define	KEY_UP 5
#define	KEY_DOWN 4

#define KEY_PLUS 24
#define KEY_MINUS 27

void	draw(t_wind *win);

void	zoom_plus(t_wind *win)
{
	win->zoom += win->zoom / 20;
	ft_printf("zoom plus\n");
}

void	zoom_minus(t_wind *win)
{
	win->zoom -= win->zoom / 20;
	ft_printf("zoom minus\n");
}

void	zoom_mouse(t_wind *win, int key)
{
	if (key == KEY_UP)
		zoom_plus(win);
	else if (key == KEY_DOWN)
		zoom_minus(win);
	else
		return ;
	draw(win);
}

void	zoom(t_wind *win, int key)
{
	if (key == KEY_PLUS)
		zoom_plus(win);
	else if (key == KEY_MINUS )
		zoom_minus(win);
	else
		return ;
	draw(win);
}
