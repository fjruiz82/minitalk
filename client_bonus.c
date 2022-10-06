/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:37:56 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/06 14:13:16 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		usleep(500);
		i--;
	}
	return (0);
}

void	confirmation_arrival(int signum)
{
	static int	received = 0;

	if (signum == SIGUSR2)
		++received;
	else
	{
		ft_printf("\n%d Successful delivery", received);
		exit(0);
	}
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
	signal(SIGUSR1, confirmation_arrival);
	signal(SIGUSR2, confirmation_arrival);
	while (ft_strlen(str) >= i)
	{
		deliver_to_server(str[i], ft_atoi(argv[1]));
		i++;
	}
	while (1)
		pause();
	return (0);
}
