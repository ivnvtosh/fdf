/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:04:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:04:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	parser(char *path);
void	event(t_data *data, t_mlx mlx);

void	fdf(char *path)
{
	t_data	data;

	data = parser(path);
	display_screen(data, data.mlx);
	event(&data, data.mlx);
}
