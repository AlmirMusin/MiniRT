/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:07:55 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:09:28 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t len;

	len = 0;
	if (s == NULL)
		write(fd, NULL, 1);
	else
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}
