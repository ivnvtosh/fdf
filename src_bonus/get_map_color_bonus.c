/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:34 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:38:35 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdlib.h>

static int	*get_color(char **ps, t_vector3 size)
{
	int	*color;
	int	i;
	int	j;

	color = (int *)malloc(sizeof(int) * ((int)size.x));
	if (color == NULL)
		terminate(MALLOC);
	i = 0;
	while (ps[i] != NULL && ps[i][0] != '\n')
	{
		j = 0;
		while (ps[i][j] != '\0' && ps[i][j] != ',')
			j++;
		if (ps[i][j] == ',')
			color[i] = ft_atox(&ps[i][j + 1]);
		else
			color[i] = 0xFFFFFF;
		i++;
	}
	return (color);
}

int	**get_map_color(t_list *list, t_vector3 size)
{
	int	**color;
	int	i;

	color = (int **)malloc(sizeof(int *) * (size.y));
	if (color == NULL)
		terminate(MALLOC);
	i = 0;
	while (list != NULL)
	{
		color[i++] = get_color(list->content, size);
		list = list->next;
	}
	return (color);
}
