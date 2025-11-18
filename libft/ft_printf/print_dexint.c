/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dexint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:20:15 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:40:45 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

int	print_dexint(int n)
{
	int			count;
	long long	num;

	num = (long long)n;
	count = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_putnbr_fd(n, 1);
	if (num < 0)
	{
		num = (-1) * num;
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
