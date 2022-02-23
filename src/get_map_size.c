/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:04:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:04:38 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector2	get_map_size(t_list *list)
{
	t_vector2	size;
	char		**ps;
	int			x;
	int			y;

	x = 0;
	ps = list->content;
	while (ps[x] != NULL && ps[x][0] != '\n')
		x += 1;
	y = 0;
	while (list != NULL)
	{
		list = list->next;
		y += 1;
	}
	size.x = x;
	size.y = y;
	return (size);
}
