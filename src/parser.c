/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:22:55 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/16 18:22:56 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../minilibx/mlx.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	leave(int code);

typedef struct s_line
{
	int				*height;
	int				*color;
	struct	s_line	*next;
}	t_line;

void	read_file(t_list **list, int fd)
{
	t_list	*temp;
	char	**ps;
	char	*s;
	
	s = get_next_line(fd);
	if (s == NULL)
		leave(2);
	while (s)
	{
		ps = ft_split(s, 32);
		free(s);
		if (ps == NULL)
			leave(2);
		temp = ft_lstnew(ps);
		if (temp == NULL)
			leave(2);
		ft_lstadd_back(list, temp);
		s = get_next_line(fd);
	}
}

void	process_map(t_list *list, t_line *line)
{
	int		*height;
	int		*color;
	char	**ps;
	char	*s;
	int		i;

	ps = list->content;
	i = 0;
	while (ps[i])
		i++;
	while (list)
	{
		line = (t_line *)malloc(sizeof(t_line));
		height = (int *)malloc(sizeof(int *) * (i + 1));
		color = (int *)ft_calloc(1, sizeof(int *) * (i + 1));
		if (line == NULL || height == NULL || color == NULL)
			leave(2);
		line->height = height;
		line->color = color;
		ps = list->content;
		s = *ps;
		while (s)
		{
			*height = ft_atoi(s);
			height++;
			while (ft_isdigit(*s))
				s++;
			if (s)
				*color++ = ft_atox(++s);
			free(*ps++);
			s = *ps;
		}
		*height = INT_MIN;
		*color = INT_MIN;
		free(list->content);
		list->content = line;
		list = list->next;
	}
}

t_map	get_map(t_list *list)
{
	t_map	map;
	t_line	*temp;
	int		**height;
	int		**color;
	int		i;

	i = ft_lstsize(list);
	height = (int **)malloc(sizeof(int *) * i);
	color = (int **)malloc(sizeof(int *) * i);
	if (height == NULL || color == NULL)
		leave(2);
	map.height = height;
	map.color = color;
	while (i > 0)
	{
		temp = list->content;
		*height++ = temp->height;
		*color++ = temp->color;
		free(temp);
		list = list->next;
		i--;
	}
	return (map);
}

t_map	parser_map(char	*path)
{
	t_map	map;
	t_list	*list;
	int		fd;

	fd = open(path, S_IREAD);
	if (fd == -1)
		leave(2);
	list = NULL;
	read_file(&list, fd);
	close(fd);
	process_map(list, NULL);
	map = get_map(list);
	return (map);
}

t_frame	get_frame(t_mlx mlx)
{
	t_frame	frame;
	int		pixel;
	int		line;
	int		endian;

	frame.screen = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	frame.buffer = mlx_get_data_addr(frame.screen, &pixel, &line, &endian);
	frame.pixel = pixel;
	frame.line = line;
	frame.endian = endian;
	return (frame);
}

t_mlx	window(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FDF");
	mlx.mode = 2;
	mlx.frame = get_frame(mlx);
	return (mlx);
}

t_vector2	get_center(int **map)
{
	t_vector2	center;
	int			y;
	int			x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != INT_MIN)
			x++;
		y++;
	}
	center.x = x / 2;
	center.y = y / 2;
	return (center);
}

t_render	preprocessing(t_map map)
{
	t_render	render;

	render.shift.x = WIDTH / 2;
	render.shift.y = HEIGHT / 2;
	render.angle.x = 0;
	render.angle.y = 0;
	render.angle.z = 0;
	render.center = get_center(map.height);
	render.zoom = 16;
	return (render);
}

t_data	parser(char	*path)
{
	t_data	data;

	data.map = parser_map(path);
	data.mlx = window();
	data.render = preprocessing(data.map);
	return (data);
}

