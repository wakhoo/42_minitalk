/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:17:30 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:42:09 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_size;
	size_t	i;
	size_t	j;

	j = 0;
	if (!dst && src && dstsize == 0)
		return (ft_strlen(src));
	dest_size = ft_strlen(dst);
	if (dstsize <= dest_size)
		return (dstsize + ft_strlen(src));
	i = dest_size;
	while ((i + j) < dstsize -1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (dest_size + ft_strlen(src));
}
