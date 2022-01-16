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
#include "mlx.h"

t_render	preprocessing(t_map map, t_mlx mlx)
{
	t_render	render;

	(void)map;
	render.shift.x = mlx.width / 2;
	render.shift.y = mlx.height / 2;
	render.angle.x = 0;
	render.angle.y = 0;
	render.angle.z = 0;
	render.zoom = 10;
	return (render);
}
