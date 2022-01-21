
#include "fdf.h"
#include "../minilibx/mlx.h"

#define MOUSE_CLICK_LEFT	1
#define MOUSE_CLICK_RIGHT	2
#define MOUSE_CLICK_MIDDLE	3
#define MOUSE_SCROLL_DOWN	4
#define MOUSE_SCROLL_UP		5
#define MOUSE_SCROLL_RIGHT	6
#define MOUSE_SCROLL_LEFT	7

void	display_screen(t_data data);

int	mouse_shift(int x, int y, t_data *data)
{
	data->render.shift.x += x - data->mouse.x;
	data->render.shift.y += y - data->mouse.y;
	data->mouse.x = x;
	data->mouse.y = y;
	display_screen(*data);
	return (0);
}

int	mouse_rotate(int x, int y, t_data *data)
{
	data->render.angle.x += (x - data->mouse.x) * 0.1;
	data->render.angle.y += (y - data->mouse.y) * 0.1;
	data->mouse.x = x;
	data->mouse.y = y;
	display_screen(*data);
	return (0);
}

void	mouse_zoom(int key, t_data *data)
{
	float	zoom;

	zoom = data->render.zoom;
	if (key == MOUSE_SCROLL_UP && zoom < 125)
	{
		data->render.zoom += zoom / 16;
	}
	else if (key == MOUSE_SCROLL_DOWN && zoom > 1.1)
	{
		data->render.zoom -= zoom / 16;
	}
	display_screen(*data);
}

int	mouse_pressed(int key, int x, int y, t_data *data)
{
	data->mouse.x = x;
	data->mouse.y = y;
	if (key == MOUSE_CLICK_LEFT)
		mlx_hook(data->mlx.win, 6, 0, mouse_shift, data);
	else if (key == MOUSE_CLICK_RIGHT)
		mlx_hook(data->mlx.win, 6, 0, mouse_rotate, data);
	else if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		mouse_zoom(key, data);
	return (0);
}

int	mouse_released(int key, int x, int y, t_data *data)
{
	mlx_hook(data->mlx.win, 6, 0, NULL, NULL);
	return (key + x + y);
}
