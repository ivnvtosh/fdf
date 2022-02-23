/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:38:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../libft/libft.h"
# include "../libgnl/get_next_line.h"
# include "../libmlx/mlx.h"

# define GOOD		0
# define ERROR		1
# define NOTHING	2
# define MALLOC		3
# define FD			4

# define WIDTH	1220
# define HEIGHT	700

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
}	t_rgb;

typedef struct s_point
{
	float	x;
	float	y;
	t_rgb	rgb;
	int		height;
	int		trgb;
}	t_point;

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
	t_vector3	size;
	int			**height;
	int			**color;
	int			**color_my;
}	t_map;

typedef struct s_render
{
	float		zoom;
	t_vector3	angle;
	t_vector2	offset;
	t_vector2	center;
	float		height;
}	t_render;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	int			mode;
	int			mode_color;
	t_render	render;
	t_frame		frame;
	t_vector2	mouse;
}	t_data;

void		display_screen(t_data data, t_mlx mlx);
void		background(t_frame frame);
int			terminate(int code);

t_point		vector_2_new(float x, float y);
t_point		vector_divide(t_point vector, float divider);
t_point		vector_reduce(t_point vector, t_point reduce);
t_point		vector_increase(t_point vector, t_point increase);

int			pixel_on_the_screen(t_point vector);
int			line_on_the_screen(t_point start, t_point end);

int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

void		write_pixel(t_frame	frame, t_point vector);
void		write_line(t_frame frame, t_point start, t_point end);

#endif
