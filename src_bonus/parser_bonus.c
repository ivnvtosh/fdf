/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:40:05 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:40:06 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_map		parse_map(char *path);
t_render	parse_var(t_vector3 size);
t_mlx		parse_mlx(void);
t_frame		parse_frame(t_mlx mlx);

t_data	parser(char *path)
{
	t_data	data;

	data.map = parse_map(path);
	data.render = parse_var(data.map.size);
	data.mode = 3;
	data.mode_color = 0;
	data.mlx = parse_mlx();
	data.frame = parse_frame(data.mlx);
	return (data);
}
