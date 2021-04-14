/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_leaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:54 by exenia            #+#    #+#             */
/*   Updated: 2021/02/03 19:42:47 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	make_obj(char **mass, t_head *head, int id)
{
	t_obj	*new_obj;
	char	**arr;

	new_obj = NULL;
	arr = NULL;
	if ((new_obj = malloc(sizeof(t_obj))) == NULL)
		return (-id * 100 - 13);
	obj_lstadd_front(&head->obj, new_obj);
	new_obj->id = id;
	if (id == 1)
		return (sphere_parse(mass, new_obj, 0));
	if (id == 2)
		return (plane_parse(mass, new_obj, 0));
	if (id == 3)
		return (square_parse(mass, new_obj, 0));
	if (id == 4)
	{
		id = cylindre_parse(mass, new_obj, 0);
		if (id > 0)
			v_normalize(new_obj->xyz_o);
		return (id);
	}
	if (id == 5)
		return (treangle_parse(mass, new_obj, 0));
	return (-1);
}

int	make_cam(char **mass, t_cam **cam)
{
	char	**arr;
	int		i;
	t_cam	*new_cam;

	arr = NULL;
	i = 0;
	if ((new_cam = malloc(sizeof(t_cam))) == NULL)
		return (-613);
	cam_lstadd_front(cam, new_cam);
	if ((i = make_xyz(new_cam->xyz, mass[1])) < 0)
		return (-600 + i);
	if ((i = make_xyz(new_cam->xyz_o, mass[2])) < 0)
		return (-602 + i);
	i = 0;
	while (i < 3)
		if (new_cam->xyz_o[i] < -1.0 || new_cam->xyz_o[i++] > 1.0)
			return (-603);
	v_normalize(new_cam->xyz_o);
	if (check_int(mass[3]) == -1)
		return (-607);
	new_cam->fov = ft_atoi(mass[3]);
	new_cam->xyz_o[0] *= -1.0;
	new_cam->xyz_o[1] *= -1.0;
	return ((new_cam->fov < 0 || new_cam->fov > 180) ? -607 : 1);
}

int	make_lt(char **mass, t_lt **lt)
{
	int		i;
	t_lt	*new_lt;

	i = 0;
	if ((new_lt = malloc(sizeof(t_lt))) == NULL)
		return (-713);
	lt_lstadd_front(lt, new_lt);
	if ((i = make_xyz(new_lt->xyz, mass[1])) < 0)
		return (-700 + i);
	if (check_double(mass[2]) < 0)
		return (-712);
	new_lt->ratio = ft_atof(mass[2]);
	if (new_lt->ratio < 0.0 || new_lt->ratio > 1.0)
		return (-712);
	if ((i = make_rgb(new_lt->rgb, mass[3])) < 0)
		return (-700 + i);
	i = 0;
	while (i < 3)
		if (new_lt->rgb[i] < 0 || new_lt->rgb[i++] > 255)
			return (-702);
	return (1);
}

int	r_parse(char **mass, t_vip *vip)
{
	if (vip->rh != -1)
		return (-820);
	if (check_int(mass[1]) == -1 || check_int(mass[2]) == -1)
		return (-819);
	if (*mass[1] == '-' || *mass[2] == '-')
		return (-819);
	if (ft_strlen(mass[1]) > 4 || ft_strlen(mass[2]) > 4)
	{
		vip->rh = 9999;
		vip->rw = 9999;
	}
	else
	{
		vip->rw = ft_atoi(mass[1]);
		vip->rh = ft_atoi(mass[2]);
		if (vip->rh == 0 || vip->rw == 0)
			return (-819);
	}
	return (1);
}

int	a_parse(char **mass, t_vip *vip, int i)
{
	if (vip->ratio != -0.1)
		return (-920);
	if (check_double(mass[1]) < 0)
		return (-912);
	vip->ratio = ft_atof(mass[1]);
	if (vip->ratio < 0.0 || vip->ratio > 1.0)
		return (-912);
	if ((i = make_rgb(vip->rgb, mass[2])) < 0)
		return (-900 + i);
	i = 0;
	while (i < 3)
		if (vip->rgb[i] < 0 || vip->rgb[i++] > 255)
			return (-902);
	return (1);
}
