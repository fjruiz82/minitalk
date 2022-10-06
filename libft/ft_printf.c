/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:07:45 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/04 10:08:48 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checker(va_list args, const char key)
{
	int	len;

	len = 0;
	if (key == 'c')
		len += char_printer(va_arg(args, int));
	else if (key == 's')
		len += str_printer(va_arg(args, char *));
	else if (key == 'p')
		len += ptr_printer(va_arg(args, unsigned long));
	else if (key == 'd' || key == 'i')
		len += int_printer(va_arg(args, int));
	else if (key == 'u')
		len += u_int_printer(va_arg(args, unsigned int));
	else if (key == 'x' || key == 'X')
		len += hex_printer(va_arg(args, unsigned int), key);
	else if (key == '%')
		len += percent_printer();
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			len += checker(args, input[i + 1]);
			i++;
		}
		else
		{
			len += char_printer(input[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
