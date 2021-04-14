/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:26:46 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

double	v_dot(double v1[3], double v2[3])
{
	double	scalar;

	scalar = v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
	return (scalar);
}

double	v_len(double v[3])
{
	return (sqrt(v_dot(v, v)));
}

double	*v_nbr(double k, double v[3], double v_return[3])
{
	v_return[0] = k * v[0];
	v_return[1] = k * v[1];
	v_return[2] = k * v[2];
	return (v_return);
}

void	v_add(double v1[3], double v2[3], double v_return[3])
{
	v_return[0] = v1[0] + v2[0];
	v_return[1] = v1[1] + v2[1];
	v_return[2] = v1[2] + v2[2];
}

double	*v_substr(double v1[3], double v2[3], double v_return[3])
{
	v_return[0] = v1[0] - v2[0];
	v_return[1] = v1[1] - v2[1];
	v_return[2] = v1[2] - v2[2];
	return (v_return);
}
