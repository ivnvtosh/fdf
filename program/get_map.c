#include <stdlib.h>
#include "../minilibx_macos/mlx.h"
#include "../ft-printf/printf.h"
#include "../get-next-line/get_next_line.h"
#include "../libft/libft.h"
#include "../libft/libft_bonus.h"
#include "stdio.h"

t_list	*read_map(int fd)
{
	t_list	*lst_str;
	t_list	*start;
	char	*s;

	ft_printf("------------------------read-------------------------\n");
	s = get_next_line(fd);
	if (s == NULL)
		return (NULL);
	ft_printf("%s", s);
	lst_str = ft_lstnew(s);
	if (lst_str == NULL)
		return (NULL);
	start = lst_str;
	s = get_next_line(fd);
	while (s)
	{
		ft_printf("%s", s);
		lst_str->next = ft_lstnew(s);
		if (lst_str->next == NULL)
		{
			ft_lstclear(&start, free);
			return (NULL);
		}
		lst_str = lst_str->next;
		s = get_next_line(fd);
	}
	ft_printf("\n");
	lst_str->next = NULL;
	return (start);
}

// t_list	*split_map(t_list *lst_s)
// {
// 	t_list	*lst_p_s;
// 	t_list	*temp;
// 	t_list	*start;
// 	char	**p_s;

// 	p_s = ft_split(lst_s->content, 32);
// 	lst_p_s = ft_lstnew(p_s);
// 	start = lst_p_s;
// 	temp = lst_s;
// 	lst_s = lst_s->next;
// 	free(temp);
// 	while (lst_s)
// 	{
// 		p_s = ft_split(lst_s->content, 32);
// 		lst_p_s->next = ft_lstnew(p_s);
// 		lst_p_s = lst_p_s->next;
// 		temp = lst_s;
// 		lst_s = lst_s->next;
// 		free(temp);
// 	}
// 	lst_p_s->next = NULL;
// 	return (start);
// }

char	***split_map(t_list *lst_s)
{
	char	***map;
	char	***start;
	char	**p_s;
	t_list	*temp;


	map = malloc(sizeof(char *) * (ft_lstsize(lst_s) + 1));
	p_s = ft_split(lst_s->content, 32);
	*map++ = p_s;
	start = map;
	temp = lst_s;
	lst_s = lst_s->next;
	free(temp);
	while (lst_s)
	{
		p_s = ft_split(lst_s->content, 32);
		*map++ = p_s;
		temp = lst_s;
		lst_s = lst_s->next;
		free(temp);
	}
	*map = NULL;
	return (start);
}

void	print_stringg(t_list *lst_s)
{
	ft_printf("------------------------string-----------------------\n");
	while (lst_s)
	{
		ft_printf("%s", lst_s->content);
		lst_s = lst_s->next;
	}
	ft_printf("\n");
}

// void	print_split(char ***map)
// {
// 	int	y;
// 	int	x;

// 	ft_printf("------------------------split------------------------\n");
// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			ft_printf("%s", map[y][x++]);
// 			if (map[y][x])
// 				ft_printf(" ");
// 		}
// 		y++;
// 	}
// 	ft_printf("\n");
// }

void	print_split(char ***map)
{
	int	y;
	int	x;

	ft_printf("------------------------split------------------------\n");
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_printf("%s", map[y][x++]);
			if (map[y][x])
				ft_printf(" ");
		}
		y++;
	}
	ft_printf("\n");
}

int	ft_atox(const char *s)
{
	int	n;

	s += 2;
	n = 0;
	while (1)
	{
		if (*s >= '0' && *s <= '9')
			n = n * 16 + *s++ - 48;
		else if (*s >= 'A' && *s <= 'F')
			n = n * 16 + *s++ - 55;
		else
			break ;
	}
	return (n);
}

void	print_atoi(int ***map)
{
	int	y;
	int	x;

	ft_printf("------------------------atoi-------------------------\n");
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_printf("%d", map[y][x][0]);
			if (map[y][x][1] != 0x990000)
				ft_printf(",0x%X", map[y][x][1]);
			x++;
			if (map[y][x])
				ft_printf(" ");
			else
				ft_printf("\n");
		}
		y++;
	}
	ft_printf("\n");
}

int	***atoi_map(char ***map_s)
{
	int	***map;
	int	i;
	int	y;
	int	x;

	y = 0;
	while (map_s[y])
		y++;
	map = malloc(sizeof(int *) * (y + 1));
	y = 0;
	while (map_s[y])
	{
		x = 0;
		while (map_s[y][x])
			x++;
		map[y] = malloc(sizeof(int *) * (x + 1));
		x = 0;
		while (map_s[y][x])
			map[y][x++] = malloc(sizeof(int) * 2);
		y++;
	}
	y = 0;
	while (map_s[y])
	{
		x = 0;
		while (map_s[y][x])
		{
			map[y][x][0] = ft_atoi(map_s[y][x]);
			i = 0;
			while (ft_isdigit(map_s[y][x][i]))
				i++;
			if (map_s[y][x][i] == ',')
				map[y][x][1] = ft_atox(&map_s[y][x][i + 1]);
			else
				map[y][x][1] = ft_atox("0x990000");
			free(map_s[y][x]);
			x++;
		}
		map[y][x] = NULL;
		free(map_s[y]);
		y++;
	}
	map[y] = NULL;
	return (map);
}

int	***get_map(int fd)
{
	t_list	*lst_s;
	char	***map_s;
	int		***map;

	lst_s = read_map(fd);
	print_stringg(lst_s);
	map_s = split_map(lst_s);
	print_split(map_s);
	map = atoi_map(map_s);
	print_atoi(map);
	return (map);
}