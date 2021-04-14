/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:48:24 by exenia            #+#    #+#             */
/*   Updated: 2020/11/06 15:06:08 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list *new_list;
	t_list *iter;

	new_list = NULL;
	iter = new_list;
	while (lst && f)
	{
		new_list = ft_lstnew(f(lst->content));
		if (new_list == NULL)
		{
			ft_lstclear(&iter, del);
			return (NULL);
		}
		ft_lstadd_back(&iter, new_list);
		lst = lst->next;
	}
	return (iter);
}
