
#include "fdf.h"

t_ptr	window()
{
	t_ptr	ptr;

	ptr.width = 1220;
	ptr.height = 700;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.width, ptr.height, "FDF");
	return (ptr);
}
