/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:02:15 by chajeon           #+#    #+#             */
/*   Updated: 2024/04/10 08:28:33 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signal)
{
	static int	bit;
	static char	tmp;

	if (signal == SIGUSR2)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int	main(int argv, char **argc)
{
	pid_t	pid;

	(void)argc;
	if (argv != 1)
	{
		ft_printf("Error: Wrong format XD\nTry ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\nMessage...SVP..\n", pid);
	signal(SIGUSR2, ft_handler);
	signal(SIGUSR1, ft_handler);
	while (argv == 1)
		pause();
	return (0);
}
