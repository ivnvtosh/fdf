/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:49:37 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/26 19:49:39 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_gnl_strlen(const char *s)
{
	size_t	slen;

	slen = 0;
	while (s[slen])
		slen++;
	return (slen);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	char	uc;

	uc = c;
	while (*s != uc && *s)
		s++;
	if (*s == uc)
		return ((char *)s);
	return (NULL);
}

static void	*ft_gnl_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	p1 = dst;
	p2 = src;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_gnl_strlen(s);
	if (slen < len)
		len = slen - start;
	if (start >= slen)
		len = 0;
	p = (char *)malloc(sizeof(*p) * (len + 1));
	if (p == NULL)
		return (NULL);
	ft_gnl_memcpy(p, &s[start], len);
	p[len] = 0;
	return (p);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	s1len;
	size_t	s2len;

	s2len = ft_gnl_strlen(s2);
	if (s1 == NULL)
		return (ft_gnl_substr(s2, 0, s2len));
	s1len = ft_gnl_strlen(s1);
	p = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (p == NULL)
		return (NULL);
	ft_gnl_memcpy(p, s1, s1len);
	ft_gnl_memcpy(p + s1len, s2, s2len + 1);
	free((char *)s1);
	return (p);
}
