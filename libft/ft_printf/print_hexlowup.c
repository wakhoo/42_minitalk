/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexlowup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:46:47 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:40:50 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

static void	re_hexlow(unsigned long long pt)
{
	char	*hexptlow;

	hexptlow = "0123456789abcdef";
	if (pt >= 16)
	{
		re_hexlow(pt / 16);
		re_hexlow(pt % 16);
	}
	else
		ft_putchar_fd(*(hexptlow + pt), 1);
}

static void	re_hexup(unsigned long long pt)
{
	char	*hexptup;

	hexptup = "0123456789ABCDEF";
	if (pt >= 16)
	{
		re_hexup(pt / 16);
		re_hexup(pt % 16);
	}
	else
		ft_putchar_fd(*(hexptup + pt), 1);
}

int	print_hexlowup(unsigned int n, char x)
{
	int				count;
	unsigned int	num;

	if (n == 0)
		ft_putchar_fd('0', 1);
	else
	{
		if (x == 'x')
			re_hexlow(n);
		else
			re_hexup(n);
	}
	num = n;
	count = 0;
	if (n == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}
