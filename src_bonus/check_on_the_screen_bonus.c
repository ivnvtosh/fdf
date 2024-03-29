/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_on_the_screen_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:37:41 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	pixel_on_the_screen(t_point vector)
{
	if (!(vector.x > 0 && vector.x < WIDTH))
		return (1);
	if (!(vector.y > 0 && vector.y < HEIGHT))
		return (1);
	return (0);
}

int	line_on_the_screen(t_point start, t_point end)
{
	if (!pixel_on_the_screen(start))
		return (0);
	if (!pixel_on_the_screen(end))
		return (0);
	start = vector_increase(start, end);
	start = vector_divide(start, 2);
	if (!pixel_on_the_screen(start))
		return (0);
	return (1);
}
