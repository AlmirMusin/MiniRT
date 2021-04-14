/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:54:32 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:02:07 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(dst);
	dst_len = i;
	if (dstsize <= dst_len)
		return (ft_strlen(src) + dstsize);
	while (j < (dstsize - dst_len - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst_len + ft_strlen(src));
}
