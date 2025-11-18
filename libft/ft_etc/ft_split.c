/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:18:39 by chajeon           #+#    #+#             */
/*   Updated: 2023/11/07 16:19:26 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_is_c(char const *s, char c)
{
	size_t	count;
	size_t	check_c;
	size_t	i;

	i = 0;
	count = 0;
	check_c = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0' && check_c == 0)
		{
			count++;
			check_c = 1;
		}
		else if (s[i] == c && s[i] != '\0')
			check_c = 0;
		i++;
	}
	return (count);
}

static char	**free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**split_words(size_t j, char **new, char const *s, char c)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (j < check_is_c(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		new[j] = ft_substr(s, start, i - start);
		if (!new[j])
			return (free_2d(new));
		j++;
	}
	new[j] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char		**new;

	if (!s)
		return (NULL);
	new = ft_calloc(sizeof(char *), (check_is_c(s, c) + 1));
	if (!new)
		return (NULL);
	new = split_words(0, new, s, c);
	return (new);
}
