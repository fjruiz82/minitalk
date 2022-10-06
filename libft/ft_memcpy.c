/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:24:09 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 14:50:08 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = dest;
	csrc = src;
	if (n == 0 || cdest == csrc)
		return (dest);
	while (n > 0)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
		n--;
	}
	return (dest);
}
