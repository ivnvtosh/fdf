/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:21:46 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 14:21:47 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	format_specifier(const char **ps, char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = print_char(va_arg(ap, int));
	else if (c == 's')
		count = print_string(va_arg(ap, char *));
	else if (c == 'p')
		count = print_pointer((unsigned long)va_arg(ap, void *));
	else if (c == 'd')
		count = print_decimal(va_arg(ap, int));
	else if (c == 'i')
		count = print_decimal(va_arg(ap, int));
	else if (c == 'u')
		count = print_unsigned_decimal(va_arg(ap, unsigned int));
	else if (c == 'x')
		count = print_hexadecimal_lowercase(va_arg(ap, unsigned int));
	else if (c == 'X')
		count = print_hexadecimal_uppercase(va_arg(ap, unsigned int));
	else if (c == '%')
		count = print_char('%');
	else
		*ps -= 1;
	*ps += 2;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			count += format_specifier(&s, *(s + 1), ap);
		else
			count += print_part(&s);
	}
	va_end(ap);
	return (count);
}
