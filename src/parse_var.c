/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:05:26 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:05:29 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector2	get_center(t_vector2 size)
{
	t_vector2	center;

	center.x = size.x / 2;
	center.y = size.y / 2;
	return (center);
}

t_render	parse_var(t_vector2 size)
{
	t_render	render;

	render.center = get_center(size);
	return (render);
}
