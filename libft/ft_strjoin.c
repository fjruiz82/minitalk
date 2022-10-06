/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:30:51 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 15:27:16 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*concat;
	unsigned int	i;

	concat = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concat == 0)
		return (0);
	i = 0;
	while (*s1 != '\0')
	{
		concat[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		concat[i] = *s2;
		i++;
		s2++;
	}
	concat[i] = '\0';
	return (concat);
}
