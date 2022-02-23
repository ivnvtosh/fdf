/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:35:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 17:35:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_map(t_list *list)
{
	char	**ps;
	int		x;
	int		i;

	x = 0;
	while (list != NULL)
	{
		i = 0;
		ps = list->content;
		while (ps[i] != NULL && ps[i][0] != '\n')
			i += 1;
		if (x == 0)
			x = i;
		if (x != i)
			terminate(ERROR);
		list = list->next;
	}
}
