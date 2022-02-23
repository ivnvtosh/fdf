/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:39:48 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:39:49 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_mlx	parse_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FDF");
	mlx.screen = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	return (mlx);
}
