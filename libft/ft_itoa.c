/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:43:09 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/05/09 16:28:20 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	j;
	char			*tmp;

	tmp = (char *)malloc(ft_nlen(n) + 1);
	if (tmp == 0)
		return (0);
	i = ft_nlen(n);
	j = n;
	if (n < 0)
	{
		j = -n;
		tmp[0] = '-';
	}
	tmp[i] = '\0';
	tmp[i - 1] = '0';
	while (j > 0)
	{
		i--;
		tmp[i] = j % 10 + 48;
		j /= 10;
	}
	return (tmp);
}
