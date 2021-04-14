/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:45:31 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:45:52 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *new_begin;

	new_begin = NULL;
	while (*lst)
	{
		new_begin = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = new_begin;
	}
	lst = NULL;
}
