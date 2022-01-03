/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:33:51 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/27 16:33:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include "stdio.h"

#include "struct.h"

int		***get_map(int fd);
void	draw(t_wind *win);
int		key_pressed(int key, t_wind *win);
int		mouse_pressed(int key, int x, int y, t_wind *win);

void	image(t_wind *win)
{
	void	*image;
	char	*buffer;
	int		color;
	int 	pixel_bits;
	int		line_bytes;
	int		endian;
	int		x;
	int		y;
	int 	pixel;

	color = 0xABCDEF;
	pixel_bits = 32;
	line_bytes = 500;
	endian = 10;
	image = mlx_new_image(win->mlx_ptr, 1220, 700);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	win->image = image;
	y = 0;
	// color = mlx_get_color_value(win->mlx_ptr, color);
	while (y < 700)
	{
		x = 0;
		while (x < 1220)
		{
			pixel = (y * line_bytes) + (x * 4);
			
			buffer[pixel] = 48;
			buffer[pixel + 1] = 38;
			buffer[pixel + 2] = 42;
			x++;
		}
		y++;
	}
}

void	panel(t_wind *win)
{
	void	*panel;
	char	*buffer;
	int		color;
	int 	pixel_bits;
	int		line_bytes;
	int		endian;
	int		x;
	int		y;
	int 	pixel;

	color = 0xABCDEF;
	pixel_bits = 32;
	line_bytes = 500;
	endian = 10;
	panel = mlx_new_image(win->mlx_ptr, 190, 100);
	buffer = mlx_get_data_addr(panel, &pixel_bits, &line_bytes, &endian);
	win->panel = panel;
	y = 0;
	// color = mlx_get_color_value(win->mlx_ptr, color);
	while (y < 100)
	{
		x = 0;
		while (x < 200)
		{
			pixel = (y * line_bytes) + (x * 4);
			
			buffer[pixel] = 54;
			buffer[pixel + 1] = 44;
			buffer[pixel + 2] = 48;
			x++;
		}
		y++;
	}
}

void	ft_fdf(t_wind *win, int fd)
{
	win->map = get_map(fd);

	win->draw_panel = 1;
	win->offset_x = 610;
	win->offset_y = 350;
	win->angl_x = 0;
	win->angl_y = -210;
	win->angl_z = -90;
	
	int	x1;
	int	y1;
	int ***map;

	map = win->map;
	y1 = 0;
	while (map[y1])
	{
		x1 = 0;
		while (map[y1][x1])
			x1++;
		y1++;
	}
	win->centre_x = x1 / 2;
	win->centre_y = y1 / 2;
	if (x1 == 500 && y1 == 499)
		win->step = 2;
	else
		win->step = 1;
	win->zoom = 800 / (x1 + y1) + 1;
	image(win);
	panel(win);
	draw(win);
}

int		mouse_pressed_re(int key, int x, int y, t_wind *win)
{
	mlx_hook(win->win_ptr, 6, 0, NULL, win);
	(void)x;
	(void)y;
	(void)win;
	return (key);
}

int	main(int argc, char **argv)
{
	t_wind	*win;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], S_IREAD);
	if (fd == -1)
		return (1);
	win = (t_wind *)malloc(sizeof(t_wind));
	if (win == NULL)
		return (1);
	win->width = 1220;
	win->height = 700;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->width, win->height, "FDF");
	mlx_do_key_autorepeaton(win->mlx_ptr);
	mlx_hook(win->win_ptr, 2, 0, key_pressed, win);
	mlx_hook(win->win_ptr, 4, 0, mouse_pressed, win);
	mlx_hook(win->win_ptr, 5, 0, mouse_pressed_re, win);
	
	ft_fdf(win, fd);
	// mlx_key_hook(win->win_ptr, key_pressed, win);
	// mlx_mouse_hook(win->win_ptr, mouse_pressed, win);
	mlx_loop(win->mlx_ptr);
	free(win);
	return (0);
}
