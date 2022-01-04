#ifndef FDF_H
# define FDF_H

typedef struct s_wind
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		width;
	int		height;
	
	void	*image;
	void	*panel;
	int		draw_panel;
	int		***map;

	float	offset_x;
	float	offset_y;

	float	angl_x;
	float	angl_y;
	float	angl_z;

	int		step;

	float	centre_x;
	float	centre_y;
	
	float	mouse_x;
	float	mouse_y;
	
	float	zoom;

	int		color;

	int		z;

}	t_wind;

#include <stdlib.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#define RADIAN 0.01745329252


#define KEY_PLUS 24
#define KEY_MINUS 27

#define	UP 5
#define	LEFT 7
#define	DOWN 4
#define	RIGHT 6

#define	MOUSE_UP 5
#define	MOUSE_LEFT 7
#define	MOUSE_DOWN 4
#define	MOUSE_RIGHT 6

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

#define KEY_ESC 53

#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_DOWN 125
#define KEY_RIGHT 124

void	status_panel(t_wind *win);
void	draw_plane(t_wind *win);
void	rotate(t_wind *win, int key);
void	shift(t_wind *win, int key);
void	shutdown(t_wind *win, int key);
void	zoom(t_wind *win, int key);
void	rotate_mouse(t_wind *win, int key);
void	zoom_mouse(t_wind *win, int key);
int		***get_map(int fd);
void	draw(t_wind *win);
int		key_pressed(int key, t_wind *win);
int		mouse_pressed(int key, int x, int y, t_wind *win);

#endif