/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 22:35:59 by exenia            #+#    #+#             */
/*   Updated: 2021/02/03 18:54:32 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

double	sphere_intersection(double *v1, double *v2, t_obj *obj)
{
	double	oc[3];
	t_eq	eq;

	v_substr(v1, obj->xyz, oc);
	eq.k1 = v_dot(v2, v2);
	eq.k2 = 2 * v_dot(oc, v2);
	eq.k3 = v_dot(oc, oc) - obj->special;
	return (quadric_equition(&eq));
}

double	plane_intersection(double o[3], double d[3], t_obj *obj)
{
	double nv_dot;
	double no_dot;
	double dd;

	dd = -v_dot(obj->xyz_o, obj->xyz);
	nv_dot = v_dot(d, obj->xyz_o);
	no_dot = v_dot(obj->xyz_o, o) + dd;
	if (nv_dot == 0.0)
		return (INFINITY);
	return ((-no_dot / nv_dot) < 0 ? INFINITY : -no_dot / nv_dot);
}

double	treangle_intersection(double o[3], double d[3], t_obj *obj)
{
	double p_vec[3];
	double t_vec[3];
	double q_vec[3];
	double u;
	double v;

	v_substr(obj->tr[1], obj->tr[0], obj->xyz);
	v_substr(obj->tr[2], obj->tr[0], obj->xyz_o);
	v_cross(obj->xyz_o, d, p_vec);
	obj->special = v_dot(obj->xyz, p_vec);
	if (obj->special < 0.00000001 && obj->special > -0.00000001)
		return (INFINITY);
	v_substr(o, obj->tr[0], t_vec);
	u = v_dot(t_vec, p_vec) / obj->special;
	if (u < 0.0 || u > 1.0)
		return (INFINITY);
	v_cross(obj->xyz, t_vec, q_vec);
	v = v_dot(d, q_vec) / obj->special;
	if (v < 0.0 || u + v > 1.0)
		return (INFINITY);
	u = v_dot(obj->xyz_o, q_vec) / obj->special;
	return (u);
}

double	square_intersection(double o[3], double d[3], t_obj *obj)
{
	double t;
	double tmp[3];

	t = treangle_intersection(o, d, obj);
	if (t > 0.000001 && t < INFINITY)
		return (t);
	v_copy(obj->tr[0], tmp);
	v_copy(obj->tr[3], obj->tr[0]);
	v_copy(tmp, obj->tr[3]);
	t = treangle_intersection(o, d, obj);
	if (t > 0.000001 && t < INFINITY)
		return (t);
	return (INFINITY);
}

double	cylindre_intersection(double o[3], double d[3], t_obj *obj)
{
	double	oc[3];
	double	m;
	double	closet_t;
	t_eq	eq;

	closet_t = INFINITY;
	v_substr(o, obj->xyz, oc);
	eq.k1 = v_dot(d, d) - v_dot(d, obj->xyz_o) * v_dot(d, obj->xyz_o);
	eq.k2 = 2.0 * (v_dot(d, oc) - v_dot(d, obj->xyz_o) * v_dot(oc, obj->xyz_o));
	eq.k3 = v_dot(oc, oc) - v_dot(oc, obj->xyz_o) *
		v_dot(oc, obj->xyz_o) - obj->special * obj->special;
	closet_t = quadric_equition(&eq);
	if (!(closet_t < INFINITY))
		return (INFINITY);
	m = v_dot(d, obj->xyz_o) * closet_t + v_dot(oc, obj->xyz_o);
	if (m >= 0.0 && m <= obj->height)
		return (closet_t);
	if (fabs(eq.t2) - fabs(closet_t) < 0.00000001)
		closet_t = eq.t1;
	else
		closet_t = eq.t2;
	m = v_dot(d, obj->xyz_o) * closet_t + v_dot(oc, obj->xyz_o);
	if (m >= 0.0 && m <= obj->height)
		return (closet_t);
	return (INFINITY);
}
