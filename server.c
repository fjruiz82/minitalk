/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:54:19 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/09/29 10:14:27 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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
			printf("\n");
			return ;
		}
		printf("%c", c);
		c = 0;
		bit = 7;
	}
}

int	main(void)
{
	//imprimo el pid del server
	printf("PID REQUIRED: %d\n", getpid());
	/*function will call the function funct if
    the process receives the signal signum. It will
    return a pointer to the funct function if successful
    or -1 in case of error.*/
	signal(SIGUSR1, handler_from_client);
	signal(SIGUSR2, handler_from_client);
	//bucle infinito para quedarse en espera, ready para
	//recibir comunicación por parte del cliente
	while (1)
		pause();
	return (0);
}
