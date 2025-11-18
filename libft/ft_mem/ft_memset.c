/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:19:27 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:39:59 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*btmp;

	i = 0;
	btmp = (unsigned char *)b;
	while (i < len)
	{
		btmp[i] = (unsigned char)c;
		i++;
	}
	return ((void *)btmp);
}
