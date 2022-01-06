/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:05:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:05:14 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shutdown(t_wind *win, int key)
{
	int	***map;

	if (key != 53)
		return ;
	map = win->map;
	// while (*map)
	// {
	// 	while (**map)
	// 		free(*(*map)++);
	// 	map++;
	// 	// free(*map++);
	// }
	free(win->map);
	free(win);
	ft_printf("bye\n");
	exit(0);
}
