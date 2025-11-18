/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:31:43 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:40:37 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

static void	check_data(const char *str, va_list args, int *cnt)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			++str;
			if (*str == 'c')
				*cnt += print_char(va_arg(args, int));
			else if (*str == 's')
				*cnt += print_str(va_arg(args, char *));
			else if (*str == 'p')
				*cnt += print_ptr(va_arg(args, unsigned long long));
			else if (*str == 'd' || *str == 'i')
				*cnt += print_dexint(va_arg(args, int));
			else if (*str == 'u')
				*cnt += print_unsign(va_arg(args, unsigned int));
			else if (*str == 'x' || *str == 'X')
				*cnt += print_hexlowup(va_arg(args, long), *str);
			else if (*str == '%')
				*cnt += print_char('%');
			++str;
		}
		else
			*cnt += print_char(*str++);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			cnt;

	cnt = 0;
	va_start(args, str);
	check_data(str, args, &cnt);
	va_end(args);
	return (cnt);
}
