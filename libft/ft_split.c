/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:36:39 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:28:08 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **mass, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		free(mass[i]);
		i++;
	}
	free(mass);
	return (NULL);
}

static char	**ft_splitting(const char *s, char c, int str_count, char **splited)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < str_count && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			splited[j][k] = s[i];
			i++;
			k++;
		}
		splited[j][k] = '\0';
		j++;
		k = 0;
	}
	splited[j] = NULL;
	return (splited);
}

static char	**ft_strs_malloc(char const *s, char c, int str_count, char **spltd)
{
	int i;
	int j;
	int str_len;

	i = 0;
	j = 0;
	str_len = 0;
	while (j < str_count && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			str_len++;
		}
		spltd[j] = (char*)malloc(str_len + 1);
		if (spltd[j] == NULL)
			return (ft_free(spltd, j));
		j++;
		str_len = 0;
	}
	return (ft_splitting(s, c, str_count, spltd));
}

static char	**ft_mass_malloc(char const *s, char c, int str_count, int i)
{
	char **splited;

	splited = NULL;
	if (s[i - 1] == c)
		str_count--;
	splited = (char**)malloc(sizeof(char*) * (str_count + 1));
	if (splited == NULL)
		return (NULL);
	return (ft_strs_malloc(s, c, str_count, splited));
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		str_count;
	char	**splited;

	i = 0;
	str_count = 0;
	splited = NULL;
	if (!s)
	{
		if ((splited = (char**)malloc(sizeof(char*))) == NULL)
			return (NULL);
		if ((splited[0] = (char*)malloc(1)) == NULL)
			return (ft_free(splited, 0));
		return (splited);
	}
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		str_count++;
	}
	return (ft_mass_malloc(s, c, str_count, i));
}
