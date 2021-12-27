/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:31:49 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/12 17:02:38 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	uc;
	size_t			i;

	if (s == NULL)
		return (NULL);
	p = s;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (p[i] == uc)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
