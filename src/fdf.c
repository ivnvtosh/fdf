/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:22:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 18:22:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../minilibx/mlx.h"

t_data		parser(char	*path);
void		display_screen(t_data data);
void		event(t_data *data);

void	fdf(char *path)
{
	t_data	data;

	data = parser(path);
	display_screen(data);
	event(&data);
}
