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
#include "mlx.h"

void		parser(t_map *map, char	*path);
t_mlx		window(void);
t_render	preprocessing(t_map map, t_mlx mlx);
void		draw(t_data data);
void		event(t_data *data);

void	fdf(char *path)
{
	t_data	data;

	parser(&data.map, path);
	data.mlx = window();
	data.render = preprocessing(data.map, data.mlx);
	draw(data);
	event(&data);
}
