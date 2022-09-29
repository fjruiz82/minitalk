/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:37:54 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/09/29 13:50:52 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handler_from_client (int signo, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 7;
    /*pid_t data type stands for process
     identification and it is used to represent
     process ids. Whenever, we want to declare
     a variable that is going to be deal with the
     process ids we can use pid_t data type.
     The type of pid_t data is a signed integer
     type (signed int or we can say int).*/
    static pid_t c_pid = 0;

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
            /* enviamos la señal para confirmar
            los bits recibidos al cliente*/
            kill(c_pid,SIGUSR1);
			bit = 7;
            c_pid = 0;
			printf("\n");
			return ;
		}
		printf("%c", c);
        kill(c_pid, SIGUSR2);
		c = 0;
		bit = 7;
	}
}

int	main (void)
{
	struct sigaction sd;

    printf("PID REQUIRED: %d\n", getpid());
	sd.sa_sigaction = handler_from_client;
    sd.sa_flags = SA_SIGINFO;  
    sigaction(SIGUSR1, &sd, NULL);
	sigaction(SIGUSR2, &sd, NULL);
	while (1)
		pause();
	return (0);
}