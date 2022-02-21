#include "fdf.h"

#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_Q		12
#define KEY_W		13
#define KEY_E		14
#define KEY_TWO		19
#define KEY_THREE	20
#define KEY_PLUS	24
#define KEY_MINUS	27
#define KEY_ESC		53
#define KEY_LEFT	123
#define KEY_RIGHT	124
#define KEY_DOWN	125
#define KEY_UP		126

static void	offset(int key, t_data *data)
{
	if (key == KEY_UP)
		data->render.offset.y -= 10;
	else if (key == KEY_LEFT)
		data->render.offset.x -= 10;
	else if (key == KEY_DOWN)
		data->render.offset.y += 10;
	else if (key == KEY_RIGHT)
		data->render.offset.x += 10;
	else
		return ;
	display_screen(*data, data->mlx);
}

static void	rotate(int key, t_data *data)
{
	if (key == KEY_W)
		data->render.angle.y -= 5;
	else if (key == KEY_A)
		data->render.angle.x -= 5;
	else if (key == KEY_S)
		data->render.angle.y += 5;
	else if (key == KEY_D)
		data->render.angle.x += 5;
	else
		return ;
	display_screen(*data, data->mlx);
}

static void	zoom(int key, t_data *data)
{
	float	zoom;

	zoom = data->render.zoom;
	if (key == KEY_PLUS && zoom < 100)
		data->render.zoom += zoom / 20;
	else if (key == KEY_MINUS)
		data->render.zoom -= zoom / 20;
	else
		return ;
	display_screen(*data, data->mlx);
}

static void	mode(int key, t_data *data)
{
	if (key == KEY_TWO)
		data->mode = 2;
	else if (key == KEY_THREE)
		data->mode = 3;
	else
		return ;
	display_screen(*data, data->mlx);
}

int	key_pressed(int key, t_data *data)
{
	offset(key, data);
	rotate(key, data);
	zoom(key, data);
	mode(key, data);
	if (key == KEY_ESC)
		terminate(GOOD);
	return (key);
}
