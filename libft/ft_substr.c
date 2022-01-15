/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:05:06 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/15 19:19:04 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < len)
		len = slen - start;
	if (start >= slen)
		len = 0;
	p = (char *)malloc(sizeof(*p) * (len + 1));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, &s[start], len);
	p[len] = 0;
	return (p);
}
