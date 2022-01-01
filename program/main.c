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

void	ft_fdf(t_wind *win, int fd)
{
	win->map = get_map(fd);

	win->offset_x = 610;
	win->offset_y = 350;
	win->angl_x = 0;
	win->angl_y = 1;
	win->zoom = 100;
	image(win);
	draw(win);
}

// void	key_wasd(int key, t_wind *win)
// {
// 	if (key == KEY_W)
// 	{
// 		win->angl_y -= 0.1;
// 		win->offset_y += 20;
// 		ft_printf("pressed the key %d *W*\n", key);
// 	}
// 	else if (key == KEY_A)
// 	{
// 		win->angl_x -= 0.1;
// 		ft_printf("pressed the key %d *A*\n", key);
// 	}
// 	else if (key == KEY_S)
// 	{
// 		win->angl_y += 0.1;
// 		win->offset_y -= 20;
// 		ft_printf("pressed the key %d *S*\n", key);
// 	}
// 	else if (key == KEY_D)
// 	{
// 		win->angl_x += 0.1;
// 		ft_printf("pressed the key %d *D*\n", key);
// 	}
// 	mlx_clear_window(win->mlx_ptr, win->win_ptr);
// 	draw(win);
// }


int		key_pressed_re(int key, t_wind *win)
{
	ft_printf("key_pressed_re\n");
	(void)win;
	return (key);
}

int		mouse_pressed_re(int key, int x, int y, t_wind *win)
{
	mlx_hook(win->win_ptr, 6, 0, NULL, win);
	ft_printf("mouse_pressed_re\n");
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
	win->mlx_ptr = mlx_init();
	// win->win_ptr = mlx_new_window(win->mlx_ptr, 1920, 1080, "FDF");
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1220, 700, "FDF");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 10, 0xe2e2e2, &argv[1][10]);
	mlx_do_key_autorepeaton(win->mlx_ptr);
	mlx_hook(win->win_ptr, 2, 0, key_pressed, win);
	mlx_hook(win->win_ptr, 3, 0, key_pressed_re, win);
	mlx_hook(win->win_ptr, 4, 0, mouse_pressed, win);
	mlx_hook(win->win_ptr, 5, 0, mouse_pressed_re, win);
	
	ft_fdf(win, fd);
	// mlx_key_hook(win->win_ptr, key_pressed, win);
	// mlx_mouse_hook(win->win_ptr, mouse_pressed, win);
	mlx_loop(win->mlx_ptr);
	free(win);
	return (0);
}
