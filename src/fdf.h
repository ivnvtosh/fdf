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

// #define WIDTH	1920
// #define HEIGHT	1080
#define WIDTH	1220
#define HEIGHT	700
// #define WIDTH	610
// #define HEIGHT	450

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
	int		mode;
	t_frame	frame;
}	t_mlx;

typedef struct s_map
{
	int	**height;
	int	**color;
}	t_map;

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_render
{
	float		zoom;
	t_vector3	angle;
	t_vector2	shift;
	t_vector2	center;
}	t_render;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_render	render;
	t_vector2	mouse;
}	t_data;

#endif
