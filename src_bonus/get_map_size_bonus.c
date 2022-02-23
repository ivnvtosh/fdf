/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:38:59 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_vector3	get_map_size(t_list *list)
{
	t_vector3	size;
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
