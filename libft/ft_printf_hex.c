/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:48:57 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/04 10:08:22 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	put_hex(unsigned int n, const char key)
{
	if (n >= 16)
	{
		put_hex(n / 16, key);
		put_hex(n % 16, key);
	}
	else
	{
		if (n <= 9)
			char_printer(n + '0');
		else
		{
			if (key == 'x')
				char_printer(n - 10 + 'a');
			if (key == 'X')
				char_printer(n - 10 + 'A');
		}
	}
}

int	hex_printer(unsigned int n, const char key)
{
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	else
		put_hex(n, key);
	return (hex_len(n));
}
