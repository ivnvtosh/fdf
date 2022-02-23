/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:19 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:38:20 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_data	parser(char *path);
void	event(t_data *data, t_mlx mlx);

void	fdf(char *path)
{
	t_data	data;

	data = parser(path);
	display_screen(data, data.mlx);
	event(&data, data.mlx);
}
