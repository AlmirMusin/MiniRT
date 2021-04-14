/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:14:56 by exenia            #+#    #+#             */
/*   Updated: 2021/01/31 02:30:50 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

double	closet_t_compute(double o[3], double d[3], t_obj *obj)
{
	double t;

	t = INFINITY;
	if (obj->id == 1)
		t = sphere_intersection(o, d, obj);
	if (obj->id == 2)
		t = plane_intersection(o, d, obj);
	if (obj->id == 5)
		t = treangle_intersection(o, d, obj);
	if (obj->id == 3)
		t = square_intersection(o, d, obj);
	if (obj->id == 4)
		t = cylindre_intersection(o, d, obj);
	return (t);
}

t_obj	*closet_inter(double o[3], double d[3], double max, t_head *head)
{
	double	closet_t;
	t_obj	*iter;
	t_obj	*closet_obj;
	double	t;

	closet_obj = NULL;
	iter = head->obj;
	closet_t = INFINITY;
	while (iter != NULL)
	{
		t = closet_t_compute(o, d, iter);
		if (t > 0.0000001 && t < max && t < closet_t)
		{
			closet_t = t;
			closet_obj = iter;
		}
		iter = iter->next;
	}
	head->tmp.closet_t = closet_t;
	return (closet_obj);
}

void	shadow_shine(t_head *head, t_tmp tmp, t_lt lt, double l[3])
{
	double dot_v;
	double ir;
	double r[3];

	dot_v = v_dot(head->tmp.n, l);
	if (tmp.id != 1 && dot_v < 0.0)
		dot_v = -dot_v;
	if (dot_v > 0.0)
	{
		ir = (lt.ratio * dot_v) / (v_len(head->tmp.n) * v_len(l));
		compute_light(head->tmp.n_rgb, lt.rgb, ir);
		v_substr(v_nbr(2.0 * v_dot(head->tmp.n, l), head->tmp.n, r), l, r);
		dot_v = v_dot(r, tmp.rev_d);
		if (dot_v > 0.0)
		{
			ir = lt.ratio * pow(dot_v / (v_len(r) * v_len(tmp.rev_d)), 100);
			compute_light(head->tmp.n_rgb, lt.rgb, ir);
		}
	}
}

void	color_calc(t_head *head, t_tmp tmp)
{
	t_lt	*iter_lt;
	double	l[3];

	iter_lt = head->lt;
	while (iter_lt)
	{
		v_substr(iter_lt->xyz, tmp.p, l);
		if (closet_inter(tmp.p, l, 0.9999, head) == NULL)
			shadow_shine(head, tmp, *iter_lt, l);
		iter_lt = iter_lt->next;
	}
}

int		trace_ray(double *o, double *d, t_head *head)
{
	t_obj	*closet_obj;

	closet_obj = closet_inter(o, d, INFINITY, head);
	head->tmp.n_rgb[0] = head->vip->rgb[0] * head->vip->ratio;
	head->tmp.n_rgb[1] = head->vip->rgb[1] * head->vip->ratio;
	head->tmp.n_rgb[2] = head->vip->rgb[2] * head->vip->ratio;
	if (closet_obj == NULL)
		return (create_rgb(head->tmp.n_rgb));
	compute_light(head->tmp.n_rgb, closet_obj->rgb, head->vip->ratio);
	point_preparation(head, o, d, closet_obj);
	color_calc(head, head->tmp);
	return (create_rgb(head->tmp.n_rgb));
}
