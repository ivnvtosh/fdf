/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:04:13 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:04:16 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libgnl/get_next_line.h"
# include "../libmlx/mlx.h"

# include <stdio.h>

# define GOOD		0
# define ERROR		1
# define NOTHING	2
# define MALLOC		3
# define FD			4

# define WIDTH	1220
# define HEIGHT	700

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

typedef struct s_frame
{
	char	*buffer;
	int		pixel;
	int		line;
	int		endian;
}	t_frame;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*screen;
}	t_mlx;

typedef struct s_map
{
	t_vector2	size;
	int			**height;
	int			**color;
}	t_map;

typedef struct s_render
{
	t_vector2	center;
}	t_render;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_render	render;
	t_frame		frame;
}	t_data;

void		display_screen(t_data data, t_mlx mlx);
void		background(t_frame frame);
int			terminate(int code);

t_vector2	vector_2_new(float x, float y);
t_vector2	vector_divide(t_vector2 vector, float divider);
t_vector2	vector_reduce(t_vector2 vector, t_vector2 reduce);
t_vector2	vector_increase(t_vector2 vector, t_vector2 increase);

int			pixel_on_the_screen(t_vector2 vector);
int			line_on_the_screen(t_vector2 start, t_vector2 end);

int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

void		write_pixel(t_frame	frame, t_vector2 vector, int trgb);
void		write_line(t_frame frame, t_vector2 start, t_vector2 end, int trgb);

#endif
