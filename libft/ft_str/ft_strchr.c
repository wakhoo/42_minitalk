/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:03:49 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:41:51 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (tmp[i])
	{
		if (tmp[i] == (char)c)
			return ((char *)tmp + i);
		i++;
	}
	if ((char)c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)s + i);
	}
	return (NULL);
}
