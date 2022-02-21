#include "fdf.h"

int			open_file(char *path);
t_list		*read_file(int fd);
void		close_file(int fd);
void		split_list(t_list *list);
void		check_map(t_list *list);
t_vector2	get_map_size(t_list *list);
int			**get_map_height(t_list *list, t_vector2 size);
int			**get_map_color(t_list *list, t_vector2 size);
void		free_split(void *p);

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
	ft_lstclear(&list, free_split);
	return (map);
}
