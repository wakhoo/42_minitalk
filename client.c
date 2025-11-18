/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:09:01 by chajeon           #+#    #+#             */
/*   Updated: 2024/04/10 08:16:58 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_char(pid_t pid, char tosend)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((tosend & (1 << bit)) != 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit++;
	}
}

static void	ft_send_message(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		ft_send_char(pid, message[i]);
		i++;
	}
	ft_send_char(pid, '\n');
	ft_send_char(pid, '\0');
}

int	main(int argv, char **argc)
{
	pid_t	pid;

	if (argv == 3 && argc[2][0] != '\0')
	{
		pid = ft_atoi(argc[1]);
		if (pid < 2 || pid > 4194304)
		{
			ft_printf("Error: PID Error\n");
			return (0);
		}
		ft_send_message(pid, argc[2]);
	}
	else
		ft_printf("Error: Wrong format XD\nTry ./client [PID] [MESSAGE]\n");
	return (0);
}
