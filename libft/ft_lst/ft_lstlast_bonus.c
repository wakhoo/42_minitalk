/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 00:14:59 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:39:20 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	j;

	j = 0;
	i = ft_lstsize(lst);
	while (j < i - 1)
	{
		lst = lst->next;
		j++;
	}
	return (lst);
}
