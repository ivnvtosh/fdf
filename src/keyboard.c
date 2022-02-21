#include "fdf.h"

#define KEY_ESC		53

int	key_pressed(int key, t_data *data)
{
	(void)data;
	if (key == KEY_ESC)
		terminate(GOOD);
	return (key);
}
