
float	ft_max(float n1, float n2)
{
	if (n1 < 0)
		n1 *= -1;
	if (n2 < 0)
		n2 *= -1;
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}