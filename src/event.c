/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:16:43 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 19:16:45 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../minilibx/mlx.h"

int		key_pressed(int key, t_data *data);
int		mouse_released(int key, int x, int y, t_data *data);
int		mouse_pressed(int key, int x, int y, t_data *data);
int		terminate(t_data *data);

void	event(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 0, key_pressed, data);
	mlx_hook(data->mlx.win, 4, 0, mouse_pressed, data);
	mlx_hook(data->mlx.win, 5, 0, mouse_released, data);
	mlx_hook(data->mlx.win, 17, 0, terminate, data);
	mlx_loop(data->mlx.mlx);
}
