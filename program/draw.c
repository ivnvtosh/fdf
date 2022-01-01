/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:04:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/01 14:04:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include <stdio.h>

#include "struct.h"

// void	draw_line_x(t_wind *win, int step_x, int step_y)
// {
// 	int	x;
// 	int	y;

// 	x = (step_x - step_y) * cos(win->angl_x);
// 	y = (step_x + step_y) * sin(win->angl_y) - win->z * win->zoom;
// 	step_x = (step_x - step_y + win->zoom) * cos(win->angl_x);
// 	while (x < step_x)
// 	{
// 		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x + win->offset_x, y + win->offset_y, win->color);
// 		x++;
// 		y++;
// 	}
// }

// void	draw_line_y(t_wind *win, int step_x, int step_y)
// {
// 	int	x;
// 	int	y;
	
// 	x = (step_x - step_y) * cos(win->angl_x);
// 	y = (step_x + step_y) * sin(win->angl_y) - win->z * win->zoom;
// 	step_y = (step_x + step_y + win->zoom) * sin(win->angl_y) - win->z * win->zoom;
// 	while (y < step_y)
// 	{
// 		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x + win->offset_x, y + win->offset_y, win->color);
// 		y++;
// 		x--;
// 	}
// }

void	panel_status(t_wind *win)
{
	char *s;

	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->panel, win->width / 10 * 9 - 100, 10);

	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 80, 20, 0xAAAAAA, "x");
	s = ft_itoa(-win->angl_x);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 60, 20, 0xAAAAAA, s);
	free(s);

	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 80, 40, 0xAAAAAA, "y");
	s = ft_itoa(-win->angl_y - 90);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 60, 40, 0xAAAAAA, s);
	free(s);




	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9, 20, 0xAAAAAA, "x");
	s = ft_itoa(win->offset_x - 610);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 + 20, 20, 0xAAAAAA, s);
	free(s);


	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9, 40, 0xAAAAAA, "y");
	s = ft_itoa(win->offset_y - 350);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 + 20, 40, 0xAAAAAA, s);
	free(s);




	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 80, 80, 0xAAAAAA, "zoom");
	s = ft_itoa(win->zoom);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 20, 80, 0xAAAAAA, s);
	free(s);

}

int	ft_max(float step_x, float step_y)
{
	if (step_x < 0)
		step_x *= -1;
	if (step_y < 0)
		step_y *= -1;
	if (step_x > step_y)
		return (step_x);
	return (step_y);
}

void	draw_line_x(t_wind *win, float x1, float y1, float x2, float y2)
{
	float	step_x;
	float	step_y;
	int		color;
	int		max;
	int		z1;
	int		z2;

	z1 = win->map[(int)y1][(int)x1][0] * win->zoom / win->zoom;
	z2 = win->map[(int)y2][(int)x2][0] * win->zoom / win->zoom;
	x1 *= win->zoom;
	x2 *= win->zoom;
	y1 *= win->zoom;
	y2 *= win->zoom;
	x1 = (x1 - y1) * cos(1);
	y1 = (x1 + y1) * sin(1) - z1;
	x2 = (x2 - y2) * cos(1);
	y2 = (x2 + y2) * sin(1) - z2;
	x1 += x1 * cos(win->angl_x);
	y1 += y1 * sin(win->angl_y) - z1;
	x2 += x2 * cos(win->angl_x);
	y2 += y2 * sin(win->angl_y) - z2;
	step_x = x2 - x1;
	step_y = y2 - y1;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	if (z1 || z2)
		color = 0xDD9922;
	else
		color = win->color;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1 + win->offset_x, y1 + win->offset_y, color);
		x1 += step_x;
		y1 += step_y;
		// color += z1;
	}
}

typedef struct s_vector
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}	t_vector;

void	draw_map(t_wind *win)
{
	int	***map;
	int	x;
	int	y;

	x = 0;
	y = 0;
	map = win->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			win->color = map[y][x][1];
			win->z = map[y][x][0];
			if (map[y][x + 1])
				draw_line_x(win, x, y, x + 1, y);
			if (map[y + 1])
				draw_line_x(win, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}

void	draw_vector(t_wind *win, float x1, float x2, float y1, float y2)
{
	float	step_x;
	float	step_y;
	int		max;


	step_x = x2 - x1;
	step_y = y2 - y1;
	max = ft_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x1, y1, win->color);
		x1 += step_x;
		y1 += step_y;
	}
}

void	new_vector(t_vector *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void	draw_space(t_wind *win)
{
	t_vector	*i;
	t_vector	*j;
	t_vector	*v;
	t_vector	*s;

	i = malloc(sizeof(t_vector));
	j = malloc(sizeof(t_vector));
	v = malloc(sizeof(t_vector));
	s = malloc(sizeof(t_vector));

	new_vector(i, win->offset_x + win->zoom * cos(win->angl_x * (3.14159265358979323846 / 180)), win->offset_y + win->zoom * sin(win->angl_x * (3.14159265358979323846 / 180)));
	new_vector(j, win->offset_x + win->zoom * cos(win->angl_y * (3.14159265358979323846 / 180)), win->offset_y + win->zoom * sin(win->angl_y * (3.14159265358979323846 / 180)));

	win->color = 0xDD5555;
	draw_vector(win, win->offset_x, i->x, win->offset_y, i->y);
	win->color = 0x55DD55;
	draw_vector(win, win->offset_x, j->x, win->offset_y, j->y);
	win->color = 0x5555DD;

	v->x = win->offset_x;
	v->y = win->offset_y;
	v->x1 = i->x + j->x - win->offset_x;
	v->y1 = i->y + j->y - win->offset_y;
	draw_vector(win, v->x, v->x1, v->y, v->y1);
	
	win->color = 0x999999;
	int	x;
	int	y;

	x = v->x1;
	y = v->y1;
	draw_vector(win, x, x + i->x - win->offset_x, y, y + i->y - win->offset_y);
	draw_vector(win, x, x + j->x - win->offset_x, y, y + j->y - win->offset_y);
	draw_vector(win, x, x + i->x + j->x - win->offset_x * 2, y, y + i->y + j->y - win->offset_y * 2);
	
	//	x
	draw_vector(win, i->x, i->x + i->x - win->offset_x, i->y, i->y + i->y - win->offset_y);
	draw_vector(win, i->x, x, i->y, y);
	draw_vector(win, i->x, x + i->x - win->offset_x, i->y, y + i->y - win->offset_y);

	//	y
	draw_vector(win, j->x, x, j->y, y);
	draw_vector(win, j->x , j->x + j->x - win->offset_x, j->y, j->y + j->y - win->offset_y);
	draw_vector(win, j->x, x + j->x - win->offset_x, j->y, y + j->y - win->offset_y);

	x = x + i->x + j->x - win->offset_x * 2;
	y = y + i->y + j->y - win->offset_y * 2;
	draw_vector(win, x, x + i->x - win->offset_x, y, y + i->y - win->offset_y);
	draw_vector(win, x, x + j->x - win->offset_x, y, y + j->y - win->offset_y);
	draw_vector(win, x, x + i->x + j->x - win->offset_x * 2, y, y + i->y + j->y - win->offset_y * 2);

	// 	// x
	// draw_vector(win, x, i->x + i->x - win->offset_x, y + i->y, i->y + i->y - win->offset_y);
	// draw_vector(win, x, x, y, y);
	// draw_vector(win, x, x + i->x - win->offset_x, y, y + i->y - win->offset_y);


	// v->x = win->offset_x;
	// v->y = win->offset_y;
	// v->x1 = win->offset_x + win->zoom;
	// v->y1 = win->offset_y - win->zoom;
	// win->color = 0x5555DD;
	// draw_vector(win, v->x, v->x1, v->y, v->y1);

	// new_vector(i, win->zoom * cos(win->angl_x * (3.14159265358979323846 / 180)), win->zoom * sin(win->angl_x * (3.14159265358979323846 / 180)));
	// new_vector(j, win->zoom * cos(win->angl_y * (3.14159265358979323846 / 180)), win->zoom * sin(win->angl_y * (3.14159265358979323846 / 180)));

	// win->color = 0xDD5555;
	// draw_vector(win, v->x1, v->x1 + i->x, v->y1, v->y1 + i->y);
	// win->color = 0x55DD55;
	// draw_vector(win, v->x1, v->x1 + j->x, v->y1,  v->y1 + j->y);

	// s->x = v->x1;
	// s->y = v->y1;
	// s->x1 = v->x1 + i->x + j->x;
	// s->y1 = v->y1 + i->y + j->y;
	// win->color = 0x5555DD;
	// draw_vector(win, s->x, s->x1, s->y, s->y1);

	// win->color = 0x999999;
	// draw_vector(win, s->x + i->x, s->x + i->x*2, i->y, i->y);

	free(i);
	free(j);
}



void	draw(t_wind *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->image, 0, 0);

	
	draw_space(win);
	// draw_map(win);



	if (win->draw_panel == 1)
		panel_status(win);
}
