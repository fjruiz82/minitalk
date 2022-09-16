/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:54:19 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/09/16 12:29:10 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler_from_client (int signum)
{
    static unsigned char c;
    static int bit;

    c = 0;
    bit = 0;
    if (signum == SIGUSR2)
        c = (1 << bit) | c;
    bit--;
    if (bit < 0)
    {
        if (c == '\0')
        {
            bit = 7;
            write(1,"\n",1);
            return ;
        }
        printf("%c", c);
        c = 0;
        bit = 7;
    }
}

int main ()
{
    //imprimo el pid del server
    printf("This is my PID: %d\n", getpid());
    /*con la función signal, if the disposition is set to a function,
    then first either the disposition is reset to SIG_DFL, or the
    signal is blocked, and then handler is called with argument
    signum*/
    signal(SIGUSR1, handler_from_client);
    signal(SIGUSR2, handler_from_client);
    //bucle infinito para quedarse en espera, ready para 
    //recibir comunicación por parte del cliente
    while (1)
        pause();
    return (0);
}
