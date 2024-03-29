/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:06:11 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:06:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector2	vector_2_new(float x, float y)
{
	t_vector2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector2	vector_divide(t_vector2 vector, float divider)
{
	vector.x /= divider;
	vector.y /= divider;
	return (vector);
}

t_vector2	vector_reduce(t_vector2 vector, t_vector2 reduce)
{
	vector.x -= reduce.x;
	vector.y -= reduce.y;
	return (vector);
}

t_vector2	vector_increase(t_vector2 vector, t_vector2 increase)
{
	vector.x += increase.x;
	vector.y += increase.y;
	return (vector);
}
