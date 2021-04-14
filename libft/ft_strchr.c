/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:28:27 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:00:14 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*c_locate;

	i = 0;
	c_locate = NULL;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		c_locate = &(((char*)s)[i]);
	return (c_locate);
}
