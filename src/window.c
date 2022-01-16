/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:23:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 18:23:16 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_frame	get_frame(t_mlx mlx)
{
	t_frame	frame;
	int		pixel;
	int		line;
	int		endian;

	frame.screen = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	frame.buffer = mlx_get_data_addr(frame.screen, &pixel, &line, &endian);
	frame.pixel = pixel;
	frame.line = line;
	frame.endian = endian;
	return (frame);
}

t_mlx	window(void)
{
	t_mlx	mlx;

	mlx.width = 1220;
	mlx.height = 700;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "FDF");
	mlx.frame = get_frame(mlx);
	return (mlx);
}
