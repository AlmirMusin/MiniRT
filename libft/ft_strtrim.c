/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:01:16 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:40:06 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_subrim(int j, int end, char const *s1, char const *set)
{
	int		i;
	char	*trimed_str;

	i = 0;
	while (set[i] && s1[end])
		if (s1[end] == set[i])
		{
			end--;
			i = 0;
		}
		else
			i++;
	i = 0;
	if (j > end)
		return (ft_strdup(""));
	if ((trimed_str = (char*)malloc(end - j + 2)) == NULL)
		return (NULL);
	while (i <= end - j)
	{
		trimed_str[i] = s1[j + i];
		i++;
	}
	trimed_str[i] = '\0';
	return (trimed_str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;
	int end;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (set[i] && s1[j])
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (ft_subrim(j, end, s1, set));
}
