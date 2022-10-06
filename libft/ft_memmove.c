/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:24:24 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 14:50:24 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	cdest = dest;
	csrc = (unsigned char *)src;
	i = 0;
	if (dest < src)
	{
		while (i < len)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (len > 0)
		{
			cdest[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (cdest);
}
