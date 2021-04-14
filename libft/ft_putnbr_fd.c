/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:19:26 by exenia            #+#    #+#             */
/*   Updated: 2020/11/05 14:08:49 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int nbr;

	if (n / 10 == 0)
	{
		if (n % 10 < 0)
		{
			nbr = n % 10 * -1 + 48;
			write(fd, "-", 1);
		}
		else
			nbr = n % 10 + 48;
		write(fd, &nbr, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		if (n % 10 < 0)
			nbr = n % 10 * -1 + 48;
		else
			nbr = n % 10 + 48;
		write(fd, &nbr, 1);
	}
}
