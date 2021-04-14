/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:07 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	get_line_count(char **mass)
{
	int line_count;

	line_count = 0;
	while (mass[line_count])
		line_count++;
	return (line_count);
}

int	check_line_count(char **mass, int id)
{
	int line_count;

	line_count = get_line_count(mass);
	if (id == 1 && line_count != 4)
		return (-100);
	if (id == 2 && line_count != 4)
		return (-200);
	if (id == 3 && line_count != 5)
		return (-300);
	if (id == 4 && line_count != 6)
		return (-400);
	if (id == 5 && line_count != 5)
		return (-500);
	if (id == 6 && line_count != 4)
		return (-600);
	if (id == 7 && line_count != 4)
		return (-700);
	if (id == 8 && line_count != 3)
		return (-800);
	if (id == 9 && line_count != 3)
		return (-900);
	return (id);
}

int	check_id(char **mass, int id)
{
	if (mass[0] == NULL)
		return (0);
	if (!ft_strncmp(mass[0], "sp", 3))
		id = 1;
	if (!ft_strncmp(mass[0], "pl", 3))
		id = 2;
	if (!ft_strncmp(mass[0], "sq", 3))
		id = 3;
	if (!ft_strncmp(mass[0], "cy", 3))
		id = 4;
	if (!ft_strncmp(mass[0], "tr", 3))
		id = 5;
	if (!ft_strncmp(mass[0], "c", 2))
		id = 6;
	if (!ft_strncmp(mass[0], "l", 2))
		id = 7;
	if (!ft_strncmp(mass[0], "R", 2))
		id = 8;
	if (!ft_strncmp(mass[0], "A", 2))
		id = 9;
	if (!ft_strncmp(mass[0], "\n", 1) || !ft_strncmp(mass[0], "\0", 1)
		|| !ft_strncmp(mass[0], "#", 1))
		id = 0;
	return (check_line_count(mass, id));
}
