/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:30:12 by chajeon           #+#    #+#             */
/*   Updated: 2024/01/10 10:39:25 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	void	*temp;

	if (!lst)
		return (NULL);
	res = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			ft_lstclear(&res, del);
			del(temp);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
		new = new->next;
	}
	return (res);
}
