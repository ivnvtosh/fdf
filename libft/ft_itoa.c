/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:54:32 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/16 15:54:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1);

static size_t	ft_nbrlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		slen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	slen = ft_nbrlen(n);
	s = (char *)malloc(sizeof(*s) * (slen + 1));
	if (s == NULL)
		return (NULL);
	s[slen--] = 0;
	if (n == 0)
		s[0] = 48;
	if (n < 0)
	{
		s[0] = 45;
		n = -n;
	}
	while (n)
	{
		s[slen--] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}
