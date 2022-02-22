#include "fdf.h"
#include <stdlib.h>

static int	*get_height(char **ps, t_vector3 size)
{
	int	*height;
	int	i;

	height = (int *)malloc(sizeof(int) * ((int)size.x));
	if (height == NULL)
		terminate(MALLOC);
	i = 0;
	while (ps[i] != NULL && ps[i][0] != '\n')
	{
		height[i] = ft_atoi(ps[i]);
		i++;
	}
	return (height);
}

int	**get_map_height(t_list *list, t_vector3 size)
{
	int	**height;
	int	i;

	height = (int **)malloc(sizeof(int *) * (size.y));
	if (height == NULL)
		terminate(MALLOC);
	i = 0;
	while (list != NULL)
	{
		height[i++] = get_height(list->content, size);
		list = list->next;
	}
	return (height);
}
