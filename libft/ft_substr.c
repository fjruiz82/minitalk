/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub
.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:14:35 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/10 14:48:00 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_foralloc(size_t s, size_t len)
{
	if (s < len)
		return (s);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
	{
		sub = malloc(sizeof(char));
		*sub = '\0';
		return (sub);
	}
	sub = (char *)malloc(ft_foralloc(ft_strlen(s), len) + 1);
	if (sub == 0)
		return (0);
	i = start;
	j = 0;
	while (s[i] && i < start + len)
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
