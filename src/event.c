/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:03:55 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:03:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pressed(int key, t_data *data);
int		mouse_released(int key, int x, int y, t_data *data);
int		mouse_pressed(int key, int x, int y, t_data *data);

void	event(t_data *data, t_mlx mlx)
{
	mlx_hook(mlx.win, 2, 0, key_pressed, data);
	mlx_hook(mlx.win, 17, 0, terminate, data);
	mlx_loop(mlx.mlx);
}
