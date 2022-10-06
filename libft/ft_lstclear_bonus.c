/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:22:23 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/09 12:46:47 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst != 0 && del != 0)
	{
		while (*lst != 0)
		{
			tmp = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}
