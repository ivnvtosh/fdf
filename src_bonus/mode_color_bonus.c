/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:13:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 20:14:00 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

#define KEY_TAB	48

void	mode_color(int key, t_data *data)
{
	if (key == KEY_TAB)
	{
		data->mode_color += 1;
		if (data->mode_color == 2)
			data->mode_color = 0;
	}
	else
		return ;
	display_screen(*data, data->mlx);
}
