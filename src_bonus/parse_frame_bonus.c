/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_frame_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:39:29 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:39:30 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_frame	parse_frame(t_mlx mlx)
{
	t_frame	frame;
	int		pixel;
	int		line;
	int		endian;

	frame.buffer = mlx_get_data_addr(mlx.screen, &pixel, &line, &endian);
	frame.pixel = pixel;
	frame.line = line;
	frame.endian = endian;
	return (frame);
}
