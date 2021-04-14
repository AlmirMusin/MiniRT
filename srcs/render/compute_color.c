/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:20:22 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	create_rgb(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	*compute_light(int c1[3], int c2[3], double r)
{
	c1[0] = c1[0] + c2[0] * r;
	c1[1] = c1[1] + c2[1] * r;
	c1[2] = c1[2] + c2[2] * r;
	if (c1[0] > 255)
		c1[0] = 255;
	if (c1[1] > 255)
		c1[1] = 255;
	if (c1[2] > 255)
		c1[2] = 255;
	return (c1);
}

int	mix_color(t_head *head, int rgb[3])
{
	head->tmp.n_rgb[0] = rgb[0] * head->vip->ratio;
	head->tmp.n_rgb[1] = rgb[1] * head->vip->ratio;
	head->tmp.n_rgb[2] = rgb[2] * head->vip->ratio;
	return (0);
}
