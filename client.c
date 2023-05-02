/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:25 by shamzaou          #+#    #+#             */
/*   Updated: 2023/05/02 10:59:36 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char *message, int pid)
{
	int	index;
	int	shift;

	index = 0;
	while (message[index] != '\0')
	{
		shift = 0;
		while (shift <= 7)
		{
			if (message[index] & (128 >> shift))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift++;
			usleep(100);
		}
		index++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	message = av[2];
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == -1)
			ft_putstr_fd("INCORRECT PID. RETRY !\n", 1);
		send_message(message, pid);
		send_message("\n", pid);
	}
	else
	{
		ft_putstr_fd("Two arguments required. PID and the message.\n", 1);
		return (0);
	}
	ft_putstr_fd(".....MESSAGE SENT TO THE SERVER.....\n", 1);
	return (0);
}

unsigned int	ft_atoi(char *str)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (*str == 0)
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] && str[i] >= '9' && str[i] <= '0')
		return (-1);
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i] - '0');
		if (result > UINT_MAX || result < 0)
			return (-1);
		i++;
	}
	return (sign * result);
}
