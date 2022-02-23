/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:40:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:40:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdlib.h>

void	split_list(t_list *list)
{
	char	**ps;

	while (list != NULL)
	{
		ps = ft_split(list->content, 32);
		if (ps == NULL)
			exit(MALLOC);
		free(list->content);
		list->content = ps;
		list = list->next;
	}
}
