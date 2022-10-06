/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:47:42 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/04 10:08:36 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_len(unsigned long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	set_ptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		set_ptr(ptr / 16);
		set_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			char_printer(ptr + '0');
		else
			char_printer(ptr - 10 + 'a');
	}
}

int	ptr_printer(unsigned long ptr)
{
	int	len;

	len = 0;
	write(1, "0x", 2);
	len += 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		len += 1;
	}
	else
	{
		set_ptr(ptr);
		len += ptr_len(ptr);
	}
	return (len);
}
