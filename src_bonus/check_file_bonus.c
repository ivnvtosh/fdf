/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:37:20 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:37:21 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <fcntl.h>
#include <unistd.h>

int	open_file(char *path)
{
	int	fd;

	fd = open(path, S_IREAD);
	if (fd == -1)
		terminate(FD);
	return (fd);
}

t_list	*read_file(int fd)
{
	t_list	*list;
	t_list	*temp;
	char	*s;

	s = get_next_line(fd);
	if (s == NULL)
		terminate(FD);
	list = NULL;
	while (s != NULL)
	{
		temp = ft_lstnew(s);
		if (temp == NULL)
			terminate(MALLOC);
		ft_lstadd_back(&list, temp);
		s = get_next_line(fd);
	}
	return (list);
}

void	close_file(int fd)
{
	fd = close(fd);
	if (fd == -1)
		terminate(FD);
}
