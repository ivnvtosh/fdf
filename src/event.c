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
#include "mlx.h"

int		key_pressed(int key, t_data *data);
void	leave(int code);

int	bye(t_data *data)
{
	(void)data;
	leave(0);
	return (0);
}

void	event(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 0, key_pressed, data);
	mlx_hook(data->mlx.win, 17, 0, bye, data);
	mlx_loop(data->mlx.mlx);
}
