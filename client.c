/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:54:14 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/09/20 10:01:12 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int deliver_to_server (unsigned char c, int pid)
{
    int i;
    unsigned char bit;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i & 1) + '0';
        if (bit == '1') 
            kill (pid, SIGUSR2);
        else
            kill (pid, SIGUSR1);
        usleep(100);
        i--;
    }
    return (0);
}

int main(int argc, char **argv)
{
    char *str;
    int i;

    i = 0;
    if (argc != 3 || !strlen(argv[2]))
    {
        printf("Something was wrong. Please try again");
        return (-1);
    }
    str = argv[2];
    while (strlen(str) >= i)
    {
        deliver_to_server(str[i], atoi(argv[1]));
        i++;
    }
    return (0);
}
