/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 10:35:23 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/17 10:35:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

static char	**ft_wordcount(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
			count++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	return ((char **)malloc(sizeof(char *) * (count + 1)));
}

static int	ft_function(char const *s, char c, char **p)
{
	int	slen;

	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		slen = 0;
		while (s[slen] != c && s[slen] != '\0')
			slen++;
		if (slen != 0)
		{
			*p = ft_substr(s, 0, slen);
			if (*p == NULL)
				return (1);
			p++;
			s = s + slen;
		}
	}
	*p = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		e;

	if (s == NULL)
		return (NULL);
	p = ft_wordcount(s, c);
	if (p == NULL)
		return (NULL);
	e = ft_function(s, c, p);
	if (e == 1)
	{
		while (*p)
			free(*p++);
		free(p);
		return (NULL);
	}
	return (p);
}
