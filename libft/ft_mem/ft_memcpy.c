/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:52:52 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:39:49 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*str;

	i = 0;
	tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (tmp == str)
		return (dst);
	while (i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	return ((void *)tmp);
}
