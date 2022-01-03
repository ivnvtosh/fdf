/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:04:43 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:04:44 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_wind
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	void	*image;
	void	*panel;
	int		draw_panel;
	int		***map;
	float	offset_x;
	float	offset_y;

	float	angl_x;
	float	angl_y;

	float	centre_x;
	float	centre_y;
	
	float	mouse_x;
	float	mouse_y;
	
	float	zoom;

	int		color;

	int		z;

}	t_wind;

#endif
