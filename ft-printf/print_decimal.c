/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:00:30 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 15:00:43 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	print_decimal(long n)
{
	int	nlen;

	if (n >= 0)
		nlen = 0;
	else
	{
		nlen = print_char('-');
		n = -n;
	}
	nlen += nbrlen(n, 10);
	print_number("0123456789", n, 10);
	return (nlen);
}
