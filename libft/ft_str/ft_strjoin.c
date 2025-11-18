/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:17:26 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:42:04 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	res_str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!res_str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		res_str[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		res_str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	return (res_str);
}
