/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:21 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

double	ft_atof(char *s)
{
	double		nbr;
	double		fst_part;
	double		scnd_part;
	double		is_negative;

	nbr = 0.0;
	fst_part = 0.0;
	scnd_part = 0.0;
	is_negative = 1.0;
	if (*s == '-')
	{
		is_negative = -1.0;
		s++;
	}
	fst_part = (double)ft_atoi(s);
	while (*s && *s != '.')
		s++;
	s++;
	scnd_part = (double)ft_atoi(s);
	scnd_part = scnd_part * pow(0.1, (double)ft_strlen(s));
	nbr = fst_part + scnd_part;
	return (nbr * is_negative);
}
