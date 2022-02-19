#include "fdf.h"



t_map	parse_map(char *path)
{
	t_map		map;
	t_list		*list;
	int			fd;

	fd = open_file(path);
	list = read_file(path, fd);
	close_file(fd);
	split_list(list);
	check_for_validity(list);
	map.size = get_map_size(list);
	map.height = get_map_height(list, map.size);
	map.color = get_map_color(list, map.size);
	ft_lstclear(&list, free_split);
	return (map);
}
