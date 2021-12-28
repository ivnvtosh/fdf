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

typedef struct s_wind
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_wind;

int	key_pressed(int key)
{
	ft_printf("pressed the key %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

t_list	*read_map(int fd)
{
	
}

void	ft_fdf(t_wind *win, int fd)
{
	t_list	*lst_str;

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1220, 700, "FDF");
	lst_str = read_map(fd);



	mlx_key_hook(win->win_ptr, key_pressed, NULL);
	mlx_loop(win->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_wind	*win;
	t_list	*lst;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], S_IREAD);
	if (fd == -1)
		return (1);
	win = (t_wind *)malloc(sizeof(t_wind));
	if (win == NULL)
		return (1);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 20, 10, 0xe2e2e2, &argv[1][10]);
	ft_fdf(win, fd);
	free(win);
	return (0);
}

// typedef struct s_win
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// }	t_win;

// typedef struct s_lst
// {
// 	int	*vertex;
// 	struct s_lst *next;
// }	t_lst;

// int	key_pressed(int key)
// {
// 	ft_printf("pressed the key %d\n", key);
// 	if (key == 53)
// 		exit(0);
// 	return (0);
// }

// t_lst	*input(int fd)
// {
// 	t_lst	*lst;
// 	t_lst	*start;
// 	char	**ps;
// 	char	*s;
// 	int		*pi;
// 	int		i;

// 	lst = malloc(sizeof(lst));
// 	if (lst == NULL)
// 		return (NULL);
// 	start = lst;
// 	s = get_next_line(fd);					//	!
// 	ps = ft_split(s, 32);
// 	free(s);
// 	if (ps == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (ps[i])
// 		i++;
// 	pi = malloc(sizeof(int *) * (i + 1));
// 	if (pi == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (ps[i])
// 	{
// 		pi[i] = ft_atoi(ps[i]) + 1;
// 		ft_printf("%d|", pi[i] - 1);
// 		free(ps[i++]);
// 	}
// 	free(ps);
// 	lst->vertex = pi;
// 	s = get_next_line(fd);
// 	ft_printf("\n");
// 	while (s)
// 	{
// 		lst->next = malloc(sizeof(lst));
// 		if (lst->next == NULL)
// 			return (NULL);
// 		lst = lst->next;
// 		ps = ft_split(s, 32);
// 		free(s);
// 		if (ps == NULL)
// 			return (NULL);
// 		i = 0;
// 		while (ps[i])
// 			i++;
// 		pi = malloc(sizeof(int *) * (i + 1));
// 		if (pi == NULL)
// 			return (NULL);
// 		i = 0;
// 		while (ps[i])
// 		{
// 			pi[i] = ft_atoi(ps[i]) + 1;
// 			ft_printf("\x1b[31m%d|\x1b[0m", pi[i] - 1);
// 			free(ps[i++]);
// 		}
// 		ft_printf("\x1b[31m%d|\x1b[0m", pi[i]);
// 		free(ps);
// 		pi[i] = 0;
// 		lst->vertex = pi;
// 		s = get_next_line(fd);
// 		ft_printf("\n");
// 	}
// 	lst->next = NULL;
// 	return (start);
// }

// void	print(t_win *t_win, t_lst *lst)
// {
// 	int	zoom;
// 	int	*pi;
// 	int	i;
// 	int	x;
// 	int	y;
// 	int	t;
// 	int	color;

// 	zoom = 16;
// 	y = 80;
// 	color = 0xffffff;
// 	ft_printf("\n");
// 	while (lst)
// 	{
// 		pi = lst->vertex;
// 		x = 400;
// 		i = 0;
// 		while (pi[i])
// 		{
// 			t = 0;
// 			while (t < zoom && pi[i + 1])
// 				mlx_pixel_put(t_win->mlx_ptr, t_win->win_ptr, x + t++, y, color);
// 			t = 0;
// 			while (t < zoom && lst->next)
// 				mlx_pixel_put(t_win->mlx_ptr, t_win->win_ptr, x, y+ t++ , color);
// 			x += zoom;
// 			ft_printf("%d|", pi[i]);
// 			i++;
// 		}
// 		ft_printf("\n");
// 		color -= 0x040000;
// 		free(pi);
// 		y += zoom;
// 		lst = lst->next;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	t_win	*t_win;
// 	t_lst	*lst;
// 	int		fd;

// 	if (argc != 2)
// 		return (1);
// 	fd = open(argv[1], S_IREAD);
// 	if (fd == -1)
// 		return (1);
// 	t_win = ft_calloc(1, sizeof(t_win));
// 	if (t_win == NULL)
// 		return (1);
// 	t_win->mlx_ptr = mlx_init();
// 	t_win->win_ptr = mlx_new_window(t_win->mlx_ptr, 1220, 700, "FDF");
// 	mlx_string_put(t_win->mlx_ptr, t_win->win_ptr, 20, 10, 0xe2e2e2, &argv[1][10]);

// 	lst = input(fd);
// 	print(t_win, lst);
	
// 	mlx_key_hook(t_win->win_ptr, key_pressed, NULL);
// 	mlx_loop(t_win->mlx_ptr);
// 	free(t_win);
// 	return (0);
// }
