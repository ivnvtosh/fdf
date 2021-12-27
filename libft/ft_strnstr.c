/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:25:42 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/12 19:59:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		i = 0;
		while (haystack[i] == needle[i] && i <= len && needle[i])
			i++;
		if (needle[i] == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
