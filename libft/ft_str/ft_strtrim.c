/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:17:54 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:42:40 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

static int	check_is_set(unsigned int c, char const *set)
{
	int	i;

	i = 0;
	while ((unsigned int)set[i])
	{
		if ((unsigned int)set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_res;
	int		begin;
	int		end;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (check_is_set((unsigned int)s1[begin], set) == 1)
		begin++;
	end = ft_strlen(s1);
	while (begin < end && check_is_set((unsigned int)s1[end - 1], set) == 1)
		end--;
	trim_res = ft_substr(s1, begin, end - begin);
	return (trim_res);
}
