/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_points_compute.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:54:58 by exenia            #+#    #+#             */
/*   Updated: 2021/02/03 18:55:08 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	points(t_obj *obj, double up[3], double right[3])
{
	double buf[3];

	v_add(obj->xyz, v_nbr(obj->special / 2, right, buf), obj->tr[0]);
	v_add(obj->tr[0], v_nbr(obj->special / 2, up, buf), obj->tr[0]);
	v_add(obj->xyz, v_nbr(obj->special / 2, right, buf), obj->tr[1]);
	v_add(obj->tr[1], v_nbr(-obj->special / 2, up, buf), obj->tr[1]);
	v_add(obj->xyz, v_nbr(-obj->special / 2, right, buf), obj->tr[2]);
	v_add(obj->tr[2], v_nbr(obj->special / 2, up, buf), obj->tr[2]);
	v_add(obj->xyz, v_nbr(-obj->special / 2, right, buf), obj->tr[3]);
	v_add(obj->tr[3], v_nbr(-obj->special / 2, up, buf), obj->tr[3]);
}

void	square_points_compute(t_obj *obj)
{
	double right[3];
	double up[3];

	up[0] = 0.0;
	up[1] = 1.0;
	up[2] = 0.0;
	if (obj->xyz_o[0] < 0.0000000001 && obj->xyz_o[0] > -0.0000000001 &&
		obj->xyz_o[1] > -INFINITY && obj->xyz_o[1] < INFINITY &&
		obj->xyz_o[2] < 0.0000000001 && obj->xyz_o[2] > -0.0000000001)
	{
		right[0] = 1.0;
		right[1] = 0.0;
		right[2] = 0.0;
	}
	else
		v_normalize(v_cross(up, obj->xyz_o, right));
	v_cross(obj->xyz_o, right, up);
	points(obj, up, right);
}
