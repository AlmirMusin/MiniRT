/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:18 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int		free_mass(char **mass)
{
	int	i;

	i = 0;
	while (mass[i] != NULL)
		free(mass[i++]);
	free(mass);
	return (1);
}

void	free_lt(t_lt *lt)
{
	t_lt	*next;

	next = NULL;
	while (lt != NULL)
	{
		next = lt->next;
		free(lt);
		lt = next;
	}
}

void	free_cam(t_cam *cam)
{
	t_cam	*next;

	next = NULL;
	while (cam != NULL)
	{
		next = cam->next;
		free(cam);
		cam = next;
	}
}

void	free_obj(t_obj *obj)
{
	t_obj	*next;

	next = NULL;
	while (obj != NULL)
	{
		next = obj->next;
		free(obj);
		obj = next;
	}
}

void	free_head(t_head *head)
{
	if (head->lt)
		free_lt(head->lt);
	if (head->cam)
		free_cam(head->cam);
	if (head->obj)
		free_obj(head->obj);
	free(head->vip);
	free(head);
}
