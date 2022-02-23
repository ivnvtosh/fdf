/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:05:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:05:51 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
