/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:17:05 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:42:45 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	if (len == 0 || !s || (unsigned int)ft_strlen(s) <= start)
	{
		sub_str = ft_calloc(1, 1);
		return (sub_str);
	}
	else if (len > ft_strlen(s) - start)
		sub_str = ft_calloc(ft_strlen(s) - start + 1, 1);
	else if ((size_t)ft_strlen(s) > len)
		sub_str = ft_calloc(len + 1, 1);
	else
		sub_str = ft_calloc((size_t)ft_strlen(s) + 1, 1);
	if (!sub_str)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
