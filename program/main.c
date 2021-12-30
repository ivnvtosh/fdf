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

typedef struct s_wind
{
	int		***map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		offset_x;
	int		offset_y;
	int		zoom;
	int		color;
	int		z;
	float	angl_x;
	float	angl_y;
}	t_wind;


int		***get_map(int fd);
void	draw(t_wind *win);
int		key_pressed(int key, t_wind *win);

void	ft_fdf(t_wind *win, int fd)
{
	win->map = get_map(fd);

	win->offset_x = 600;
	win->offset_y = 180;
	win->angl_x = 0.2;
	win->angl_y = 0.6;
	win->zoom = 10;
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

int	mouse_pressed(int key, t_wind *win)
{
	(void)win;
	if (key == 1)
	{
		// win->angl_y -= 0.1;
		// win->offset_y = 20;
		ft_printf("pressed the key %d *left click*\n", key);
		// mlx_clear_window(win->mlx_ptr, win->win_ptr);
		// draw(win);
	}
	else if (key == 2)
	{
		win->angl_y -= 0.1;
		ft_printf("pressed the key %d *right click*\n", key);
	}
	else if (key == 5)
	{
		ft_printf("pressed the key %d *up*\n", key);
	}
	else if (key == 7)
	{
		ft_printf("pressed the key %d *left*\n", key);
	}
	else if (key == 4)
	{
		ft_printf("pressed the key %d *down*\n", key);
	}
	else if (key == 6)
	{
		ft_printf("pressed the key %d *right*\n", key);
	}
	else
	{
		ft_printf("%d", key);
	}
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
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1220, 700, "FDF");
	// win->win_ptr = mlx_new_window(win->mlx_ptr, 122, 70, "FDF");
	// mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 10, 0xe2e2e2, &adrgv[1][10]);
	ft_fdf(win, fd);
	mlx_key_hook(win->win_ptr, key_pressed, win);
	mlx_mouse_hook(win->win_ptr, mouse_pressed, win);
	// mlx_do_key_autorepeaton(win->mlx_ptr);
	mlx_loop(win->mlx_ptr);
	free(win);
	return (0);
}
