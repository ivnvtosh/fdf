#include "fdf.h"
#include <stdlib.h>

void	free_split(void *p)
{
	char	**ps;
	int		i;

	if (p == NULL)
		return ;
	i = 0;
	ps = p;
	while (ps[i] != NULL)
		free(ps[i++]);
	free(ps);
}
