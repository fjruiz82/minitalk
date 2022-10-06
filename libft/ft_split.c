/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:07:19 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/10 09:42:31 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_slicer(char *tmp, unsigned int len, int portion)
{
	char			**aux;
	unsigned int	i;
	unsigned int	j;

	aux = (char **)malloc(sizeof(char *) * (portion + 1));
	if (aux == 0)
		return (0);
	i = 0;
	j = 0;
	if (tmp[i] != '\0')
	{
		aux[j] = ft_strdup(&tmp[i]);
		j++;
	}
	i++;
	while (i < len)
	{
		if (tmp[i] != '\0' && tmp[i - 1] == '\0')
		{
			aux[j++] = ft_strdup(&tmp[i]);
		}
		i++;
	}
	aux[j] = 0;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	int				portion;
	char			*tmp;
	char			**aux;

	len = ft_strlen(s);
	tmp = ft_strdup(s);
	if (tmp == 0)
		return (0);
	portion = 0;
	i = 0;
	while (i < len)
	{
		if (tmp[i] == c)
			tmp[i] = '\0';
		else if (i == 0 || tmp[i - 1] == '\0')
			portion++;
		i++;
	}
	aux = ft_slicer(tmp, len, portion);
	free(tmp);
	return (aux);
}
