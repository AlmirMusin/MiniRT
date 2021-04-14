/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:39:29 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:04:15 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*c_locate;

	i = ft_strlen(s);
	c_locate = NULL;
	while (i > 0 && s[i] != c)
		i--;
	if (s[i] == c)
		c_locate = &((char*)s)[i];
	return (c_locate);
}
