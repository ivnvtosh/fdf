
int	ft_isdigit(int c);

unsigned int	ft_atox(const char *s)
{
	int	n;

	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	s += 2;
	n = 0;
	while (1)
	{
		if (ft_isdigit(*s))
			n = n * 16 + *s++ - 48;
		else if (*s >= 65 && *s <= 70)
			n = n * 16 + *s++ - 55;
		else if (*s >= 97 && *s <= 102)
			n = n * 16 + *s++ - 87;
		else
			break ;
	}
	return (n);
}
