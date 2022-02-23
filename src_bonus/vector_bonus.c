/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:40:53 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:40:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	vector_2_new(float x, float y)
{
	t_point	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_point	vector_divide(t_point vector, float divider)
{
	vector.x /= divider;
	vector.y /= divider;
	return (vector);
}

t_point	vector_reduce(t_point vector, t_point reduce)
{
	vector.x -= reduce.x;
	vector.y -= reduce.y;
	return (vector);
}

t_point	vector_increase(t_point vector, t_point increase)
{
	vector.x += increase.x;
	vector.y += increase.y;
	return (vector);
}
