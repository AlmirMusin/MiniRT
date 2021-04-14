/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:47:55 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:29:48 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_make_str(int len, long long int nbr, int is_negative, int n)
{
	char *str;

	str = NULL;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	if ((nbr = (long long int)n) < 0)
		nbr *= -1;
	if ((str = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	while (nbr != 0)
	{
		len--;
		str[len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (is_negative == 1)
		str[len - 1] = 45;
	return (str);
}

char		*ft_itoa(int n)
{
	long long int	nbr;
	int				is_negative;
	long long int	len;
	char			*str;

	nbr = (long long int)n;
	is_negative = 0;
	len = 0;
	str = NULL;
	if ((nbr = (long long int)n) == 0)
	{
		if ((str = (char*)malloc(2)) == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (nbr < 0)
	{
		is_negative = 1;
		nbr *= -1;
		len++;
	}
	return (ft_make_str(len, nbr, is_negative, n));
}
