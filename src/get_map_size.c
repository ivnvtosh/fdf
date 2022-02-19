#include "fdf.h"

t_vector2	get_map_size(t_list *list)
{
	t_vector2	size;
	char		**ps;
	int			x;
	int			y;

	x = 0;
	ps = list->content;
	while (ps[x] != NULL && ps[x][0] != '\n')
		x += 1;
	y = 0;
	while (list != NULL)
	{
		list = list->next;
		y += 1;
	}
	size.x = x;
	size.y = y;
	return (size);
}
