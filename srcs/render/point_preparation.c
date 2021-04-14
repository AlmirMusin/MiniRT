/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_preparation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:19:00 by exenia            #+#    #+#             */
/*   Updated: 2021/02/03 18:54:12 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	norm_vector_compute(t_head *head, double o[3], t_obj *obj)
{
	double v1[3];
	double v2[3];
	double m;

	if (head->tmp.id == 1)
		v_substr(head->tmp.p, obj->xyz, head->tmp.n);
	if (head->tmp.id == 2)
		v_copy(obj->xyz_o, head->tmp.n);
	if (head->tmp.id == 5 || head->tmp.id == 3)
	{
		v_substr(obj->tr[1], obj->tr[0], v1);
		v_substr(obj->tr[2], obj->tr[0], v2);
		v_cross(v2, v1, head->tmp.n);
	}
	if (head->tmp.id == 4)
	{
		v_substr(o, obj->xyz, v2);
		m = v_dot(head->tmp.d, obj->xyz_o);
		m *= head->tmp.closet_t;
		m += v_dot(v2, obj->xyz_o);
		v_substr(head->tmp.p, obj->xyz, head->tmp.n);
		v_substr(head->tmp.n, v_nbr(m, obj->xyz_o, v1), head->tmp.n);
	}
}

void	point_preparation(t_head *head, double o[3], double d[3], t_obj *obj)
{
	double	v1[3];

	head->tmp.id = obj->id;
	v_add(o, v_nbr(head->tmp.closet_t * 0.9999, d, head->tmp.p), head->tmp.p);
	v_nbr(-1.0, d, head->tmp.rev_d);
	v_copy(d, head->tmp.d);
	norm_vector_compute(head, o, obj);
	if (head->tmp.id == 1)
	{
		v_substr(o, obj->xyz, v1);
		if (v_len(v1) - sqrt(obj->special) < 0.00001)
			v_nbr(-1.0, head->tmp.n, head->tmp.n);
	}
	v_normalize(head->tmp.n);
}

double	quadric_equition(t_eq *eq)
{
	double discr;

	eq->closet_t = INFINITY;
	discr = (eq->k2 * eq->k2) - (4 * eq->k1 * eq->k3);
	if (discr < 0.0)
		return (INFINITY);
	eq->t1 = (-eq->k2 + sqrt(discr)) / (2 * eq->k1);
	eq->t2 = (-eq->k2 - sqrt(discr)) / (2 * eq->k1);
	eq->closet_t = INFINITY;
	if (eq->t1 < eq->t2 && eq->t1 > 0.0 && eq->t2 > 0.0)
		eq->closet_t = eq->t1;
	if (eq->t2 < eq->t1 && eq->t1 > 0.0 && eq->t2 > 0.0)
		eq->closet_t = eq->t2;
	if (eq->t1 > 0.0 && eq->t2 < 0.0)
		eq->closet_t = eq->t1;
	if (eq->t2 > 0.0 && eq->t1 < 0.0)
		eq->closet_t = eq->t2;
	return (eq->closet_t);
}
