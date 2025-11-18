/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 06:18:56 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:38:22 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int	ft_isalnum(int alnum)
{
	if (alnum >= 48 && alnum <= 57)
		return (1);
	else if (alnum >= 'A' && alnum <= 'z')
	{
		if (!(alnum >= 91 && alnum <= 96))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
