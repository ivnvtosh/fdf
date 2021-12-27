/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_uppercase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:09:16 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 15:09:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	print_hexadecimal_uppercase(unsigned int n)
{
	print_number("0123456789ABCDEF", n, 16);
	return (nbrlen(n, 16));
}
