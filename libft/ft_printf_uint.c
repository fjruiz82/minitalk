/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:51:11 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/04 10:08:44 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_u_nlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*tmp;

	i = ft_u_nlen(n);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == 0)
		return (0);
	tmp[i] = '\0';
	while (n != 0)
	{
		tmp[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (tmp);
}

int	u_int_printer(int n)
{
	int		len;
	char	*uint_to_str;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		uint_to_str = ft_uitoa(n);
		len = str_printer(uint_to_str);
		free(uint_to_str);
	}
	return (len);
}
