
#include "fdf.h"
#include "../minilibx/mlx.h"

#define MOUSE_CLICK_LEFT	1
#define MOUSE_CLICK_RIGHT	2
#define MOUSE_CLICK_WHEEL	3
#define MOUSE_DOWN			4
#define MOUSE_UP			5
#define MOUSE_RIGHT			6
#define MOUSE_LEFT			7

void	draw(t_data data);

int	mouse_shift(int x1, int y1, t_data *data)
{
	int	x;
	int	y;

	x = data->mouse.x;
	y = data->mouse.y;
	if (y - y1 > 0)
		data->render.shift.y -= (y - y1);
	else
		data->render.shift.y += (y1 - y);
	if (x - x1 > 0)
		data->render.shift.x -= (x - x1);
	else
		data->render.shift.x += (x1 - x);
	data->mouse.x = x1;
	data->mouse.y = y1;
	draw(*data);
	return (x + y);
}

int	mouse_rotate(int x1, int y1, t_data *data)
{
	int	x;
	int	y;

	x = data->mouse.x;
	y = data->mouse.y;
	if (y - y1 > 0)
		data->render.angle.y += (y1 - y) * 0.1;
	else
		data->render.angle.y -= (y - y1) * 0.1;
	if (x - x1 > 0)
		data->render.angle.x -= (x1 - x) * 0.1;
	else
		data->render.angle.x += (x - x1) * 0.1;
	data->mouse.x = x1;
	data->mouse.y = y1;
	draw(*data);
	return (x + y);
}

void	mouse_zoom(t_data *data, int key)
{
	float	zoom;

	zoom = data->render.zoom;
	if (key == MOUSE_UP && zoom < 100)
	{
		data->render.zoom += zoom / 16;
	}
	else if (key == MOUSE_DOWN && zoom > 1.1)
	{
		data->render.zoom -= zoom / 16;
	}
	else
		return ;
	draw(*data);
}

int	mouse_pressed(int key, int x, int y, t_data *data)
{
	data->mouse.x = x;
	data->mouse.y = y;
	if (key == MOUSE_CLICK_LEFT)
		mlx_hook(data->mlx.win, 6, 0, mouse_shift, data);
	else if (key == MOUSE_CLICK_RIGHT)
		mlx_hook(data->mlx.win, 6, 0, mouse_rotate, data);
	else if (key == MOUSE_UP || key == MOUSE_DOWN)
		mouse_zoom(data, key);
	return (0);
}

int	mouse_released(int key, int x, int y, t_data *data)
{
	mlx_hook(data->mlx.win, 6, 0, NULL, data);
	return (key + x + y);
}
