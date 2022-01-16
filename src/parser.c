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

void	get_map(t_list *list, t_map *map)
{
	t_line	*temp;
	int		**height;
	int		**color;
	int		i;

	i = ft_lstsize(list);
	height = (int **)malloc(sizeof(int *) * i);
	color = (int **)malloc(sizeof(int *) * i);
	if (height == NULL || color == NULL)
		leave(2);
	map->height = height;
	map->color = color;
	while (i > 0)
	{
		temp = list->content;
		*height++ = temp->height;
		*color++ = temp->color;
		free(temp);
		list = list->next;
		i--;
	}
}

void	parser(t_map *map, char	*path)
{
	t_list	*list;
	int		fd;

	fd = open(path, S_IREAD);
	if (fd == -1)
		leave(2);
	list = NULL;
	read_file(&list, fd);
	close(fd);
	process_map(list, NULL);
	get_map(list, map);
}
