/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:40:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:40:37 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdlib.h>

void	free_split(void *p)
{
	char	**ps;
	int		i;

	if (p == NULL)
		return ;
	i = 0;
	ps = p;
	while (ps[i] != NULL)
		free(ps[i++]);
	free(ps);
}
