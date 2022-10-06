/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:54:19 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/06 10:17:17 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_from_client(int signum)
{
	static unsigned char	c = 0;
	static int				bit = 7;

	if (signum == SIGUSR2)
		c = (1 << bit) | c;
	bit--;
	if (bit < 0)
	{
		if (c == '\0')
		{
			bit = 7;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		bit = 7;
	}
}

int	main(void)
{
	ft_printf("PID REQUIRED: %d\n", getpid());
	signal(SIGUSR1, handler_from_client);
	signal(SIGUSR2, handler_from_client);
	while (1)
		pause();
	return (0);
}
