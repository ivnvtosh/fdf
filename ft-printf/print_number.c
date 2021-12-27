/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:12:34 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 15:14:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

void	print_number(char *s, unsigned long n, unsigned long mode)
{
	if (n < mode)
		ft_putchar_fd(s[n], 1);
	else
	{
		print_number(s, n / mode, mode);
		print_number(s, n % mode, mode);
	}
}
