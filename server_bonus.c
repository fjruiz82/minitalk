/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:37:54 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/10/06 14:24:47 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_from_client(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 7;
	static pid_t			c_pid = 0;

	(void)context;
	if (c_pid == 0)
		c_pid = info->si_pid;
	if (signo == SIGUSR2)
		c = (1 << bit) | c;
	bit--;
	if (bit < 0)
	{
		if (c == '\0')
		{
			kill(c_pid, SIGUSR1);
			bit = 7;
			c_pid = 0;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		kill(c_pid, SIGUSR2);
		c = 0;
		bit = 7;
	}
}

int	main(void)
{
	struct sigaction	sd;

	ft_printf("PID REQUIRED: %d\n", getpid());
	sd.sa_sigaction = handler_from_client;
	sd.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sd, NULL);
	sigaction(SIGUSR2, &sd, NULL);
	while (1)
		pause();
	return (0);
}
