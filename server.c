/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:22 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/31 19:51:31 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	if (pid == 0)
		return ;
	ft_putstr_fd("Server pid:[", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("]\n", 1);
}

void	signal_handler(int signal)
{
	static int	index = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c |= 1 << (7 - index);
	index++;
	if (index == 8)
	{
		write(1, &c, 1);
		index = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = &signal_handler;
	action.sa_flags = SA_RESTART;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	print_pid();
	while (1)
	{
		pause();
	}
	return (0);
}
