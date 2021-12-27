/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:24:12 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/19 20:24:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);

int		print_part(const char **ps);
void	print_number(char *s, unsigned long n, unsigned long mode);
int		nbrlen(unsigned long n, int mode);

int		print_char(char c);
int		print_string(char *s);
int		print_pointer(unsigned long int n);
int		print_decimal(long n);
int		print_unsigned_decimal(unsigned int n);
int		print_hexadecimal_lowercase(unsigned int n);
int		print_hexadecimal_uppercase(unsigned int n);

#endif
