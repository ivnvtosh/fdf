/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:11 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:37:12 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	background(t_frame frame)
{
	int		pixel;
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = (y * frame.line) + (x * 4);
			frame.buffer[pixel] = 48;
			frame.buffer[pixel + 1] = 38;
			frame.buffer[pixel + 2] = 42;
			x++;
		}
		y++;
	}
}
