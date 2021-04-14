/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:31:51 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 13:56:48 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*chr;

	i = 0;
	chr = NULL;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
		{
			chr = &((unsigned char*)s)[i];
			return (chr);
		}
		i++;
	}
	return (chr);
}
