/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:26:21 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 14:55:47 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	s1cp = ((unsigned char *)s1);
	s2cp = ((unsigned char *)s2);
	i = 0;
	while ((s1cp[i] != '\0' || s2cp[i] != '\0') && i < n)
	{
		if (s1cp[i] > s2cp[i])
		{
			return (1);
		}
		else if (s1cp[i] < s2cp[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
