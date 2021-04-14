/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:59:20 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:41:37 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	start_t;

	i = 0;
	start_t = (size_t)start;
	if (!s)
		return (ft_strdup(""));
	if (start_t >= ft_strlen(s))
		return (ft_strdup(""));
	substr = (char*)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len && s[i + start_t])
	{
		substr[i] = s[i + start_t];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
