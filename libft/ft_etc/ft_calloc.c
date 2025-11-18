/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:31:55 by chajeon           #+#    #+#             */
/*   Updated: 2023/11/07 18:02:43 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	max_int;

	max_int = 2147483647;
	if (count * size > max_int || count > max_int || size > max_int)
		return (NULL);
	arr = (void *)malloc((count) * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, (count * size));
	return (arr);
}
