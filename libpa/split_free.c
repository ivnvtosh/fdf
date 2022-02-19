#include "fdf.h"
#include <stdlib.h>

void	free_split(char	**ps)
{
	int	i;

	i = 0;
	while (ps[i] != NULL)
		free(ps[i++]);
	free(ps);
}
