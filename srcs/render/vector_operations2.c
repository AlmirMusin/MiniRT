/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:38:37 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	v_normalize(double v[3])
{
	double	len;

	len = v_len(v);
	v[0] = v[0] / len;
	v[1] = v[1] / len;
	v[2] = v[2] / len;
}

double	*v_cross(double v1[3], double v2[3], double v3[3])
{
	v3[0] = v1[1] * v2[2] - v1[2] * v2[1];
	v3[1] = v1[2] * v2[0] - v1[0] * v2[2];
	v3[2] = v1[0] * v2[1] - v1[1] * v2[0];
	return (v3);
}

void	v_copy(double v1[3], double v2[3])
{
	v2[0] = v1[0];
	v2[1] = v1[1];
	v2[2] = v1[2];
}
