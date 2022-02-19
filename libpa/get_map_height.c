#include "fdf.h"
#include <stdlib.h>

int	*get_height(char **ps, t_vector2 size)
{
	int	*height;
	int	i;

	height = (int *)malloc(sizeof(int *) + (size.x));
	if (height == NULL)
		terminate(MALLOC);
	i = 0;
	while (*ps != NULL && **ps != '\n')
	{
		height[i] = ft_atoi(ps[i]);
		i++;
	}
	return (height);
}

int	**get_map_height(t_list *list, t_vector2 size)
{
	int	**height;
	int	i;

	height = (int **)malloc(sizeof(int **) + (size.y));
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
