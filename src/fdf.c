
#include "fdf.h"

void		parser(t_map *map, char	*path);
t_ptr		window();
t_render	preprocessing(t_map map, t_ptr ptr);

void	fdf(char *path)
{
	t_data	data;

	parser(&data.map, path);	
	data.ptr = window();
	data.render = preprocessing(data.map, data.ptr);
}
