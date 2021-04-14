/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:16:14 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 13:58:59 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_cp;
	unsigned char	*src_cp;

	i = 0;
	dst_cp = (unsigned char*)dst;
	src_cp = (unsigned char*)src;
	if (dst_cp == src_cp || len == 0)
		return (dst_cp);
	if (dst < src)
		while (i < len)
		{
			dst_cp[i] = src_cp[i];
			i++;
		}
	else
		while (len--)
			dst_cp[len] = src_cp[len];
	return (dst);
}
