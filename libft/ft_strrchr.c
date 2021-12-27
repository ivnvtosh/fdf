/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:28:16 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/12 16:28:41 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			slen;

	uc = c;
	slen = ft_strlen(s);
	while (s[slen] != uc && slen)
		slen--;
	if (s[slen] == uc)
		return ((char *)&s[slen]);
	return (NULL);
}
