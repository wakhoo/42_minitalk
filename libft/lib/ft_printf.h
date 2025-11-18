/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:36:30 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:43:31 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_ptr(unsigned long long pt);
int	print_dexint(int n);
int	print_unsign(unsigned int unsi);
int	print_hexlowup(unsigned int n, char x);

#endif
