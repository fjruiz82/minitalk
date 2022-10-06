/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:36:43 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 14:56:07 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hcp;
	char	*ncp;
	size_t	i;
	size_t	j;
	size_t	nlen;

	hcp = (char *)haystack;
	ncp = (char *)needle;
	i = 0;
	nlen = ft_strlen(needle);
	if (*ncp == 0)
		return (hcp);
	while (hcp[i] != '\0' && i < len)
	{
		j = 0;
		while (hcp[i + j] == ncp[j] && ncp[j] != '\0' && j + i < len)
			j++;
		if (j == nlen)
			return (&hcp[i]);
		i++;
	}
	return (0);
}
