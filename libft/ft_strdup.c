/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:48:24 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 22:35:15 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char *str;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_strcpy(str, s1));
}
