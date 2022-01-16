
void	fdf(char *path);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	fdf(*++argv);
	return (10);
}
