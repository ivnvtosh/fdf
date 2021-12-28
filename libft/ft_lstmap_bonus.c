/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:29:27 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/20 22:29:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tab;
	t_list	*tabegin;

	if (lst == NULL)
		return (NULL);
	tab = ft_lstnew(f(lst->content));
	if (tab == NULL)
		return (NULL);
	tabegin = tab;
	lst = lst->next;
	while (lst)
	{
		tab->next = ft_lstnew(f(lst->content));
		if (tab == NULL)
		{
			ft_lstclear(&tabegin, del);
			return (NULL);
		}
		lst = lst->next;
		tab = tab->next;
	}
	return (tabegin);
}
