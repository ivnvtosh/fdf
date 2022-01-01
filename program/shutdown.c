/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:05:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft-printf/printf.h"
#include "struct.h"
#include <stdlib.h>

#define KEY_ESC 53

void	shutdown(t_wind *win, int key)
{
	int	***map;
	int	x;
	int	y;

	if (key == 53)
	{
		ft_printf("bye\n");
		map = win->map;
		y = 0;
		while (map[y])
		{
			x = 0;
			while (map[y][x])
				free(map[y][x++]);
			free(map[y++]);
		}
		free(map);
		free(win);
		exit(0);
	}
}
