/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:19:01 by chajeon           #+#    #+#             */
/*   Updated: 2023/11/08 08:18:20 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long long save)
{
	int	count;

	count = 0;
	if (save == 0)
		return (1);
	else if (save < 0)
		count++;
	while (save)
	{
		save /= 10;
		count++;
	}
	return (count);
}

static char	*num_to_str(char *res, int n, char *int_p, int count)
{
	long long	save;

	save = (long long)n;
	if (n < 0)
		save = save * (-1);
	res[count] = '\0';
	if (n >= 0)
	{
		while (0 <= --count)
		{
			res[count] = *int_p + (save % 10);
			save = save - save % 10;
			save /= 10;
		}
	}
	else
	{
		while (0 < --count)
		{
			res[count] = *int_p + (save % 10);
			save = save - save % 10;
			save /= 10;
		}
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*int_p;
	char	*res;
	int		save;
	int		count;

	int_p = "0123456789";
	save = n;
	count = 0;
	res = NULL;
	count = count_len((long long)save);
	res = ft_calloc(count + 1, 1);
	if (!res)
		return (NULL);
	res = num_to_str(res, n, int_p, count);
	if (n < 0)
		res[0] = '-';
	return (res);
}
