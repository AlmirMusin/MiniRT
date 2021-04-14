/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:14:09 by exenia            #+#    #+#             */
/*   Updated: 2020/11/10 11:32:39 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!big || !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] && little[j] && i < len)
	{
		while (big[i + j] && little[j] && big[i + j] == little[j] &&
			i + j < len)
			j++;
		if (!little[j])
			return (&((char*)big)[i]);
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}
