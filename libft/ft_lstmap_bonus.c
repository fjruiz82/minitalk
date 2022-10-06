/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:51:10 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 13:39:21 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*l;

	if (lst == 0)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == 0)
		return (0);
	l = new_lst;
	while (lst->next)
	{
		l->next = ft_lstnew(f(lst->next->content));
		if (!l->next)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		l = l->next;
		lst = lst->next;
	}
	return (new_lst);
}
