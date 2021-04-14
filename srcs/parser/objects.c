/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:29:06 by exenia            #+#    #+#             */
/*   Updated: 2021/02/03 18:48:34 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	sphere_parse(char **mass, t_obj *obj, int i)
{
	if ((i = make_xyz(obj->xyz, mass[1])) < 0)
		return (-100 + i);
	if (check_double(mass[2]) < 0)
		return (-108);
	if ((obj->special = ft_atof(mass[2]) / 2.0) <= 0.0)
		return (-108);
	if ((i = make_rgb(obj->rgb, mass[3])) < 0)
		return (-100 + i);
	i = 0;
	while (i < 3)
		if (obj->rgb[i] < 0 || obj->rgb[i++] > 255)
			return (-102);
	obj->special = obj->special * obj->special;
	return (1);
}

int	plane_parse(char **mass, t_obj *obj, int i)
{
	if ((i = make_xyz(obj->xyz, mass[1])) < 0)
		return (-200 + i);
	if ((i = make_xyz(obj->xyz_o, mass[2])) < 0)
		return (-202 + i);
	i = 0;
	while (i < 3)
		if (obj->xyz_o[i] < -1.0 || obj->xyz_o[i++] > 1.0)
			return (-203);
	v_normalize(obj->xyz_o);
	if ((i = make_rgb(obj->rgb, mass[3])) < 0)
		return (-200 + i);
	i = 0;
	while (i < 3)
		if (obj->rgb[i] < 0 || obj->rgb[i++] > 255)
			return (-202);
	return (1);
}

int	square_parse(char **mass, t_obj *obj, int i)
{
	if ((i = make_xyz(obj->xyz, mass[1])) < 0)
		return (-300 + i);
	if ((i = make_xyz(obj->xyz_o, mass[2])) < 0)
		return (-302 + i);
	i = 0;
	while (i < 3)
		if (obj->xyz_o[i] < -1.0 || obj->xyz_o[i++] > 1.0)
			return (-303);
	if (check_double(mass[3]) < 0)
		return (-309);
	v_normalize(obj->xyz_o);
	if ((obj->special = ft_atof(mass[3])) <= 0)
		return (-309);
	if ((i = make_rgb(obj->rgb, mass[4])) < 0)
		return (-300 + i);
	i = 0;
	while (i < 3)
		if (obj->rgb[i] < 0 || obj->rgb[i++] > 255)
			return (-302);
	square_points_compute(obj);
	return (1);
}

int	cylindre_parse(char **mass, t_obj *obj, int i)
{
	if ((i = make_xyz(obj->xyz, mass[1])) < 0)
		return (-400 + i);
	if ((i = make_xyz(obj->xyz_o, mass[2])) < 0)
		return (-402 + i);
	i = 0;
	while (i < 3)
		if (obj->xyz_o[i] < -1.0 || obj->xyz_o[i++] > 1.0)
			return (-403);
	if (check_double(mass[3]) < 0)
		return (-410);
	if ((obj->special = ft_atof(mass[3]) / 2.0) <= 0.0)
		return (-410);
	if (check_double(mass[4]) < 0)
		return (-411);
	if ((obj->height = ft_atof(mass[4])) <= 0.0)
		return (-411);
	if ((i = make_rgb(obj->rgb, mass[5])) < 0)
		return (-400 + i);
	i = 0;
	while (i < 3)
		if (obj->rgb[i] < 0 || obj->rgb[i++] > 255)
			return (-402);
	v_substr(obj->xyz, v_nbr(obj->height / 2,
		obj->xyz_o, obj->tr[0]), obj->xyz);
	return (1);
}

int	treangle_parse(char **mass, t_obj *obj, int i)
{
	if (make_xyz(obj->tr[0], mass[1]) < 0)
		return (-504 + i);
	if (make_xyz(obj->tr[1], mass[2]) < 0)
		return (-505 + i);
	if (make_xyz(obj->tr[2], mass[3]) < 0)
		return (-506 + i);
	if ((i = make_rgb(obj->rgb, mass[4])) < 0)
		return (-500 + i);
	i = 0;
	while (i < 3)
		if (obj->rgb[i] < 0 || obj->rgb[i++] > 255)
			return (-502);
	return (1);
}
