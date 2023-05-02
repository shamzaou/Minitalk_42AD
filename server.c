/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:22 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/02 09:14:18 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    print_pid(void)
{
    int pid;

    pid = getpid();
    if (pid == 0)
        return;
    write(1, "Server pid:[",12);
    ft_putnbr_fd(pid, 1);
    write(1, "]\n",2);
}

void    signal_handler(int signal)
{
    static int index = 0;
    static char c = 0;

    if (signal == SIGUSR2)
        c |= (1 << index);
    index++;
    if (index == 8)
    {
        write(1, &c, 1);
        index = 0;
        c = 0;
    }
}

int main()
{
    struct sigaction action;

    action.sa_handler = &signal_handler;
    
    print_pid();
    while (1)
    {
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
        pause();
    }
    
}