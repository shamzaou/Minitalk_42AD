/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:25 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/02 09:13:47 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_message(char *message, int pid)
{
    int index;
    int shift;

    index = 0;
    while (message[index] != '\0')
    {
        shift = 0;
        while (shift <= 7)
        {
            if (message[index] & (128 >> shift))
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            shift++;
            usleep(100);
        }
        index++;
    }
}

int main(int ac, char **av)
{
	int     pid;
	char 	*message;

    pid = ft_atoi(av[1]);
	message = av[2];
	if(ac == 3)
	{
    	send_message(message, pid);
        send_message('\0', pid);
	}
	else
	{
		ft_putstr_fd("Two arguments required ONLY. PID and the message.\n",1);
		return(0);
	}
	ft_putstr_fd(".....MESSAGE SENT TO THE SERVER.....\n",1);
	return (0);
}