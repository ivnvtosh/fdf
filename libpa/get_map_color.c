#include "fdf.h"
#include <stdlib.h>

int	*get_color(char **ps, t_vector2 size)
{
	int	*color;
	int	i;
	int	j;

	color = (int *)malloc(sizeof(int *) + (size.x));
	if (color == NULL)
		terminate(MALLOC);
	i = 0;
	while (*ps != NULL && **ps != '\n')
	{
		j = 0;
		while (ps[i][j] != '\0' && ps[i][j] != ',')
			j++;
		if (ps[i][j] != '\0')
			color[i] = ft_atox(ps[i]);
		else
			color[i] = 0;
		i++;
	}
	return (color);
}

int	**get_map_color(t_list *list, t_vector2 size)
{
	int	**color;
	int	i;

	color = (int **)malloc(sizeof(int **) + (size.y));
	if (color == NULL)
		terminate(MALLOC);
	i = 0;
	while (list != NULL)
	{
		color[i++] = get_color(list->content, size);
		list = list->next;
	}
	return (color);
}
