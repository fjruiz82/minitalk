/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:21:29 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/13 11:59:24 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (0);
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len]))
		len--;
	str = ft_substr(&s1[i], 0, len + 1 - i);
	if (str == 0)
		return (0);
	str[ft_strlen(str)] = '\0';
	return (str);
}
