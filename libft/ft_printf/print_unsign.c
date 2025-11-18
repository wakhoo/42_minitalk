/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:29:01 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:41:07 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

static void	re_unsign(unsigned int unsi)
{
	if (unsi >= 10)
	{
		re_unsign(unsi / 10);
		re_unsign(unsi % 10);
	}
	else
		ft_putchar_fd(unsi + '0', 1);
}

int	print_unsign(unsigned int unsi)
{
	int	count;

	count = 0;
	re_unsign(unsi);
	if (unsi == 0)
		return (1);
	while (unsi > 0)
	{
		unsi /= 10;
		count++;
	}
	return (count);
}
