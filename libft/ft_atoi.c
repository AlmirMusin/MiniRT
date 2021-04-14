/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:40:55 by exenia            #+#    #+#             */
/*   Updated: 2020/11/10 11:48:24 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int				i;
	int				is_negative;
	long long int	nbr;

	is_negative = 0;
	i = 0;
	nbr = 0;
	while (str[i] && ((str[i] > 8 && str[i] < 14) || str[i] == 32))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	while (str[i] && (str[i] > 47 && str[i] < 58))
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	if (is_negative)
		nbr *= -1;
	return ((int)nbr);
}
