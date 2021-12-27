/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:33:51 by ccamie            #+#    #+#             */
/*   Updated: 2021/12/27 16:33:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], S_IREAD);
	if (fd == -1)
		return (1);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 512, 512, "FDF");































	char	*s;
	char	**p;

	int	i;

	int	*pd;

	int d;

	int	x;
	int	y;
	int	step_x;
	int	step_y;


	s = get_next_line(fd);
	step_y = 100;
	while(s)
	{
		p = ft_split(s, ' ');
		free(s);

		i = 0;
		while (p[i])
			i++;

		pd = malloc(sizeof(char *) * (i + 1));
		if (pd == NULL)
			return (0);

		i = 0;
		while (p[i])
		{
			pd[i] = ft_atoi(p[i]);
			free(p[i]);
			i++;
		}
		free(p);
		d = i;


		i = 0;
		x = 100;
		y = step_y;
		step_x = 100;
		while (i < d)
		{
			step_x += 10;
			while (x < step_x)
				mlx_pixel_put(mlx_ptr, win_ptr, x++, y, 0xffffff);
			y = step_y;
			while (y < step_y + 10)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y++, 0xffffff);
			i++;
		}
		step_y += 10;
		free(pd);
		s = get_next_line(fd);
	}




















	mlx_loop(mlx_ptr);
	return (0);
}
