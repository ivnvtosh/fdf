/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_lowercase.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:07:47 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 15:07:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	print_hexadecimal_lowercase(unsigned int n)
{
	print_number("0123456789abcdef", n, 16);
	return (nbrlen(n, 16));
}
