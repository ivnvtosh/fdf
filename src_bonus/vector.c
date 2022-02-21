#include "fdf.h"

t_vector2	vector_divide(t_vector2 vector, int divider)
{
	vector.x /= divider;
	vector.y /= divider;
	return (vector);
}

t_vector2	vector_reduce(t_vector2 vector, t_vector2 reduce)
{
	vector.x -= reduce.x;
	vector.y -= reduce.y;
	return (vector);
}

t_vector2	vector_increase(t_vector2 vector, t_vector2 increase)
{
	vector.x += increase.x;
	vector.y += increase.y;
	return (vector);
}