#include "fdf.h"

void	fdf(char *path);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (NOTHING);
	fdf(argv[1]);
	return (GOOD);
}
