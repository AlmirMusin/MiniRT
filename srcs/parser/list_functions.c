/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:00 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 23:57:06 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	cam_lstadd_front(t_cam **lst, t_cam *new)
{
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
	new->next->prev = new;
}

void	lt_lstadd_front(t_lt **lst, t_lt *new)
{
	new->next = *lst;
	*lst = new;
}

void	obj_lstadd_front(t_obj **lst, t_obj *new)
{
	new->next = *lst;
	*lst = new;
}

void	make_linked_list(t_cam **cam)
{
	t_cam *iter;

	iter = *cam;
	while (iter->next != NULL)
		iter = iter->next;
	iter = iter->prev;
	free(iter->next);
	iter->next = NULL;
	iter->next = *cam;
	(*cam)->prev = iter;
}
