/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:22:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 18:22:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define KEY_ESC	53

int	terminate(t_data *data);

int	key_pressed(int key, t_data *data)
{
	printf("key %d\n", key);
	if (key == KEY_ESC)
		terminate(data);
	return (key);
}
