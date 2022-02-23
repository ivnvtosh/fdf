/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_color_my_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:38:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdlib.h>

static int	*get_color(int *height, t_vector3 size)
{
	int	*color;
	int	x;

	color = (int *)malloc(sizeof(int) * ((int)size.x));
	if (color == NULL)
		terminate(MALLOC);
	x = 0;
	while (x < size.x)
	{
		if (height[x] == 0)
			color[x] = 0x601060;
		if (height[x])
			color[x] = 0xffa510;
		x++;
	}
	return (color);
}

int	**get_map_color_my(int **height, t_vector3 size)
{
	int	**color;
	int	y;

	color = (int **)malloc(sizeof(int *) * (size.y));
	if (color == NULL)
		terminate(MALLOC);
	y = 0;
	while (y < size.y)
	{
		color[y] = get_color(height[y], size);
		y++;
	}
	return (color);
}
