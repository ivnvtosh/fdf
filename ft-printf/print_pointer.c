/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:54:53 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 14:54:54 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	print_pointer(unsigned long n)
{
	ft_putstr_fd("0x", 1);
	print_number("0123456789abcdef", n, 16);
	return (nbrlen(n, 16) + 2);
}
