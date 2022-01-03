#include <stdlib.h>
#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include "struct.h"

void	status_panel(t_wind *win)
{
	char *s;

	if (win->draw_panel != 1)
		return ;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->panel, win->width / 10 * 9 - 100, 10);

	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 80, 20, 0xAAAAAA, "x");
	s = ft_itoa(-win->angl_x);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 60, 20, 0xAAAAAA, s);
	free(s);

	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 80, 40, 0xAAAAAA, "y");
	s = ft_itoa(-win->angl_y);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 60, 40, 0xAAAAAA, s);
	free(s);

	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9, 20, 0xAAAAAA, "x");
	s = ft_itoa(win->offset_x - 610);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 + 20, 20, 0xAAAAAA, s);
	free(s);

	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9, 40, 0xAAAAAA, "y");
	s = ft_itoa(-win->offset_y + 350);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 + 20, 40, 0xAAAAAA, s);
	free(s);

	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 80, 80, 0xAAAAAA, "zoom");
	s = ft_itoa(win->zoom * 10);
	mlx_string_put(win->mlx_ptr, win->win_ptr, win->width / 10 * 9 - 20, 80, 0xAAAAAA, s);
	free(s);

}
