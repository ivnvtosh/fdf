#include "fdf.h"
#include <stdlib.h>

void	split_list(t_list *list)
{
	char	**ps;

	while (list != NULL)
	{
		ps = ft_split(list->content, 32);
		if (ps == NULL)
			terminate(MALLOC);
		free(list->content);
		list->content = ps;
		list = list->next;
	}
}
