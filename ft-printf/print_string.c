/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:54:15 by ccamie            #+#    #+#             */
/*   Updated: 2021/11/24 14:54:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../libft/libft.h"

int	print_string(char *s)
{
	if (s == NULL)
		return (print_string("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
