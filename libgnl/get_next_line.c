/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:47:55 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/26 19:47:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);

static char	*ft_joinline(char *first, char *last, char **remainder)
{
	char	*temp;
	ssize_t	i;

	i = 0;
	while (first[i] != '\n' && first[i] != '\0')
		i++;
	temp = ft_gnl_substr(first, 0, ++i);
	if (temp == NULL)
		return (NULL);
	last = ft_gnl_strjoin(last, temp);
	free(temp);
	if (last == NULL)
		return (NULL);
	temp = *remainder;
	*remainder = ft_gnl_substr(first, i, ft_gnl_strlen(first) - i);
	free(temp);
	if (*remainder == NULL)
	{
		free(last);
		return (NULL);
	}
	return (last);
}

static int	ft_read(char *buffer, char **remainder, char **line, int fd)
{
	ssize_t	count;

	if (*remainder)
	{
		*line = ft_gnl_substr(*remainder, 0, ft_gnl_strlen(*remainder));
		free(*remainder);
		*remainder = NULL;
		if (*line == NULL)
			return (-1);
	}
	else
		*line = NULL;
	count = read(fd, buffer, BUFFER_SIZE);
	if (count <= 0)
		return (count);
	buffer[count] = '\0';
	while (count == BUFFER_SIZE && ft_gnl_strchr(buffer, '\n') == NULL)
	{
		*line = ft_gnl_strjoin(*line, buffer);
		if (*line == NULL)
			return (-1);
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
	}
	return (1);
}

static char	*ft_getline(char *buffer, char **remainder, int fd)
{
	char	*line;
	ssize_t	error;

	if (*remainder && ft_gnl_strchr(*remainder, '\n'))
		return (ft_joinline(*remainder, NULL, remainder));
	error = ft_read(buffer, remainder, &line, fd);
	if (error == -1)
	{
		free(line);
		return (NULL);
	}
	if (error == 0)
		return (line);
	line = ft_joinline(buffer, line, remainder);
	return (line);
}

char	*get_next_line(int fd)
{
	char static	*remainder;
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	line = ft_getline(buffer, &remainder, fd);
	if (line == NULL || (remainder && remainder[0] == '\0'))
	{
		free(remainder);
		remainder = NULL;
	}
	free(buffer);
	return (line);
}
