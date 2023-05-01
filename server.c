/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:22 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/02 02:55:56 by shamzaou         ###   ########.fr       */
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

void    signal_handler
int main()
{
    print_pid();
    
    
}