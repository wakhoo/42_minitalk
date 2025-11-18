/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 06:07:30 by chajeon           #+#    #+#             */
/*   Updated: 2024/04/10 08:30:02 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_handler(int signal, siginfo_t *arg_sig, void *x)
{
	static int	bit;
	static char	tmp;
	pid_t		pid;

	(void) x;
	pid = arg_sig->si_pid;
	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (tmp != '\0')
			ft_putchar_fd(tmp, 1);
		else
			kill(pid, SIGUSR1);
		bit = 0;
		tmp = 0;
	}
}

int	main(int argv, char **argc)
{
	pid_t				pid;
	struct sigaction	arg_sig;

	(void)argc;
	if (argv != 1)
	{
		ft_printf("Error: Wrong format XD\nTry ./server\n");
		return (0);
	}
	arg_sig.sa_flags = SA_SIGINFO;
	arg_sig.sa_sigaction = &ft_handler;
	pid = getpid();
	ft_printf("PID: %d\n~~Bonus Server~~\nMessage...SVP..\n", pid);
	sigaction(SIGUSR1, &arg_sig, NULL);
	sigaction(SIGUSR2, &arg_sig, NULL);
	while (argv == 1)
		pause();
	return (0);
}
