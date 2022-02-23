/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:06:02 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:06:07 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	terminate(int code)
{
	if (code == ERROR)
		ft_putstr_fd("Error\n", 2);
	exit(code);
	return (NOTHING);
}
