#include "fdf.h"

int			open_file(char *path);
t_list		*read_file(int fd);
void		close_file(int fd);
void		split_list(t_list *list);
void		check_map(t_list *list);
t_vector3	get_map_size(t_list *list);
int			**get_map_height(t_list *list, t_vector3 size);
int			**get_map_color(t_list *list, t_vector3 size);
int			**get_map_color_my(int **height, t_vector3 size);
void		free_split(void *p);

float	get_map_size_height(t_map map)
{
	t_vector2	step;
	int			max;

	step.y = 0;
	max = -__INT_MAX__ - 1;
	while (step.y < map.size.y)
	{
		step.x = 0;
		while (step.x < map.size.x)
		{
			if (map.height[(int)step.y][(int)step.x] > max)
				max = map.height[(int)step.y][(int)step.x];
			step.x += 1;
		}
		step.y += 1;
	}
	return (max);
}

t_map	parse_map(char *path)
{
	t_map		map;
	t_list		*list;
	int			fd;

	fd = open_file(path);
	list = read_file(fd);
	close_file(fd);
	split_list(list);
	check_map(list);
	map.size = get_map_size(list);
	map.height = get_map_height(list, map.size);
	map.color = get_map_color(list, map.size);
	map.color_my = get_map_color_my(map.height, map.size);
	map.size.z = get_map_size_height(map);
	ft_lstclear(&list, free_split);
	return (map);
}
