/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:23:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 18:23:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../minilibx/mlx.h"
#include <limits.h>

t_xyz	get_center(int **map)
{
	t_xyz	center;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != INT_MIN)
			x++;
		y++;
	}
	center.x = x / 2;
	center.y = y / 2;
	return (center);
}

t_render	preprocessing(t_map map, t_mlx mlx)
{
	t_render	render;

	render.shift.x = mlx.width / 2;
	render.shift.y = mlx.height / 2;
	render.angle.x = 0;
	render.angle.y = 0;
	render.angle.z = 0;
	render.center = get_center(map.height);
	render.zoom = 16;
	return (render);
}
