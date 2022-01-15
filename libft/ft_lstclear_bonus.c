/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:41:31 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/19 22:41:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tab;

	while (lst)
	{
		tab = *lst;
		*lst = (*lst)->next;
		del(tab->content);
		free(tab);
	}
	*lst = NULL;
}
