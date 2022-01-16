/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:22:29 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 18:22:31 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>

typedef struct s_frame
{
	void	*screen;
	char	*buffer;
	int		pixel;
	int		line;
	int		endian;
}	t_frame;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_frame	frame;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_map
{
	int		**height;
	int		**color;
}	t_map;

typedef struct s_angle
{
	float	x;
	float	y;
	float	z;
}	t_angle;

typedef struct s_shift
{
	float	x;
	float	y;
	float	z;
}	t_shift;

typedef struct s_centre
{
	float	x;
	float	y;
}	t_centre;

typedef struct s_render
{
	float		zoom;
	t_angle		angle;
	t_shift		shift;
	t_centre	centre;
}	t_render;

typedef struct s_mouse
{
	float	x;
	float	y;
}	t_mouse;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_render	render;
	t_mouse		mouse;
}	t_data;

#endif
