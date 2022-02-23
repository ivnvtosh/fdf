/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:39:10 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/23 19:39:11 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	fdf(char *path);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (NOTHING);
	fdf(argv[1]);
	return (GOOD);
}
