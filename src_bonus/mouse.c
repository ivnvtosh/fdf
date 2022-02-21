#include "fdf.h"

#define MOUSE_CLICK_LEFT	1
#define MOUSE_CLICK_RIGHT	2
#define MOUSE_CLICK_MIDDLE	3
#define MOUSE_SCROLL_DOWN	4
#define MOUSE_SCROLL_UP		5
#define MOUSE_SCROLL_RIGHT	6
#define MOUSE_SCROLL_LEFT	7

static int	mouse_offset(int x, int y, t_data *data)
{
	data->render.offset.x += x - data->mouse.x;
	data->render.offset.y += y - data->mouse.y;
	data->mouse.x = x;
	data->mouse.y = y;
	display_screen(*data, data->mlx);
	return (0);
}

static int	mouse_rotate(int x, int y, t_data *data)
{
	data->render.angle.x += (x - data->mouse.x) * 0.1;
	data->render.angle.y += (y - data->mouse.y) * 0.1;
	data->mouse.x = x;
	data->mouse.y = y;
	display_screen(*data, data->mlx);
	return (0);
}

static void	mouse_zoom(int key, t_data *data)
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
	display_screen(*data, data->mlx);
}

int	mouse_pressed(int key, int x, int y, t_data *data)
{
	data->mouse.x = x;
	data->mouse.y = y;
	if (key == MOUSE_CLICK_LEFT)
		mlx_hook(data->mlx.win, 6, 0, mouse_offset, data);
	else if (key == MOUSE_CLICK_RIGHT)
		mlx_hook(data->mlx.win, 6, 0, mouse_rotate, data);
	else if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		mouse_zoom(key, data);
	return (key + x + y);
}

int	mouse_released(int key, int x, int y, t_data *data)
{
	mlx_hook(data->mlx.win, 6, 0, NULL, NULL);
	return (key + x + y);
}
