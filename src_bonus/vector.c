#include "fdf.h"

t_point	vector_2_new(float x, float y)
{
	t_point	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_point	vector_divide(t_point vector, float divider)
{
	vector.x /= divider;
	vector.y /= divider;
	return (vector);
}

t_point	vector_reduce(t_point vector, t_point reduce)
{
	vector.x -= reduce.x;
	vector.y -= reduce.y;
	return (vector);
}

t_point	vector_increase(t_point vector, t_point increase)
{
	vector.x += increase.x;
	vector.y += increase.y;
	return (vector);
}
