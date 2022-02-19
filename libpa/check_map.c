#include "fdf.h"

void	check_map(t_list *list)
{
	char	**ps;
	int		x;
	int		i;

	x = 0;
	while (list != NULL)
	{
		i = 0;
		ps = list->content;
		while (ps[i] != NULL && ps[i][0] != '\n')
			i += 1;
		if (x == 0)
			x = i;
		if (x != i)
			terminate(ERROR);
		list = list->next;
	}
}
