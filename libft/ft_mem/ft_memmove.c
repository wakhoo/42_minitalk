/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:09:13 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:39:54 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cp_src;
	unsigned char	*cp_dst;

	i = 0;
	cp_src = (unsigned char *)src;
	cp_dst = (unsigned char *)dst;
	if (!src && !dst)
		return (dst);
	while (i < len)
	{
		if (cp_src > cp_dst)
			cp_dst[i] = cp_src[i];
		else
			cp_dst[len - i - 1] = cp_src[len - i - 1];
		i++;
	}
	return (dst);
}
