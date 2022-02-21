
#include "fdf.h"
#include <stdlib.h>

int	terminate(int code)
{
	if (code == ERROR)
		ft_putstr_fd("Error\n", 2);
	exit(code);
	return (NOTHING);
}