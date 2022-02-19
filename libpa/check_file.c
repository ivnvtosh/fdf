#include "fdf.h"
#include <fcntl.h>

int	open_file(char *path)
{
	int	fd;

	fd = open(path, S_IREAD);
	if (fd == -1)
		terminate(FD);					//	check
	return (fd);
}

t_list	*read_file(char *path, int fd)
{
	t_list	*list;
	t_list	*temp;
	char	*s;
	
	s = get_next_line(fd);
	if (s == NULL)
		terminate(FD);
	while (s != NULL)
	{
		temp = ft_lstnew(s);
		if (temp == NULL)
			terminate(MALLOC);
		ft_lstadd_back(&list, temp);
		s = get_next_line(fd);
	}
	return (list);
}

void	close_file(int fd)
{
	fd = close(fd);
	if (fd == -1)
		terminate(FD);
}
