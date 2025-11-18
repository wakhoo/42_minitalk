/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:29:12 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:41:55 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup_str;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s1;
	if (ft_strlen(str) > 0)
		dup_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	else
		dup_str = (char *)malloc(1 * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	while (str[i])
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
