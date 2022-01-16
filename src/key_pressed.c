/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:22:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 18:22:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		leave(int code);

int	key_pressed(int key, t_data *data)
{
	(void)data;
	printf("key %d\n", key);
	if (key == 53)
		leave(0);
	return (key);
}
