#include "fdf.h"

t_data	parser(char *path);
void	event(t_data *data, t_mlx mlx);

void	fdf(char *path)
{
	t_data	data;

	data = parser(path);
	display_screen(data, data.mlx);
	event(&data, data.mlx);
}
