/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:04:43 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:04:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define KEY_ESC		53

int	key_pressed(int key, t_data *data)
{
	(void)data;
	if (key == KEY_ESC)
		terminate(GOOD);
	return (key);
}
