/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:44:04 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:40:55 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

static void	re_ptr(unsigned long long pt)
{
	if (pt >= 16)
	{
		re_ptr(pt / 16);
		re_ptr(pt % 16);
	}
	else
	{
		if (pt <= 9)
			ft_putchar_fd(pt + '0', 1);
		else
			ft_putchar_fd(pt - 10 + 'a', 1);
	}
}

int	print_ptr(unsigned long long pt)
{
	int					count;
	unsigned long long	num;

	num = pt;
	count = 0;
	ft_putstr_fd("0x", 1);
	if (pt == 0)
		ft_putchar_fd('0', 1);
	else
		re_ptr(pt);
	if (num == 0)
		return (3);
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	count += 2;
	return (count);
}
