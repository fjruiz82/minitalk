/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:54:14 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/05 13:19:32 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	deliver_to_server(unsigned char c, int pid)
{
	int				i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i & 1) + '0';
		if (bit == '1')
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	size_t	i;

	if (argc != 3 || ft_strlen(argv[2]) == 0)
	{
		ft_printf("Something was wrong. Please try again");
		return (-1);
	}
	str = argv[2];
	i = 0;
	while (ft_strlen(str) >= i)
	{
		deliver_to_server(str[i], ft_atoi(argv[1]));
		i++;
	}
	return (0);
}
