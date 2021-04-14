/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:09 by exenia            #+#    #+#             */
/*   Updated: 2021/02/01 17:28:52 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int		make_rgb(int dst[3], char *mass)
{
	int		i;
	char	**arr;

	i = 0;
	arr = NULL;
	if ((arr = ft_split(mass, ',')) == NULL)
		return (-13);
	while (arr[i])
		if (check_int(arr[i++]) == -1 && free_mass(arr))
			return (-2);
	if (i != 3 && free_mass(arr))
		return (-2);
	i = 0;
	while (arr[i])
	{
		dst[i] = ft_atoi(arr[i]);
		i++;
	}
	free_mass(arr);
	return (1);
}

int		check_double(char *arr)
{
	int p_count;
	int i;

	p_count = 0;
	i = 0;
	if (*arr == '-')
		arr++;
	if (*arr < '0' || *arr > '9')
		return (-1);
	while (*arr)
	{
		if ((*arr < '0' || *arr > '9') && *arr != '.')
			return (-1);
		if (*arr == '.')
			p_count++;
		arr++;
	}
	if (p_count > 1)
		return (-1);
	return (1);
}

int		make_xyz(double dst[3], char *mass)
{
	int		i;
	char	**arr;

	i = 0;
	arr = NULL;
	if ((arr = ft_split(mass, ',')) == NULL)
		return (-13);
	while (arr[i])
	{
		if (check_double(arr[i]) == -1 && free_mass(arr))
			return (-1);
		i++;
	}
	if (i != 3 && free_mass(arr))
		return (-1);
	i = 0;
	while (arr[i])
	{
		dst[i] = ft_atof(arr[i]);
		i++;
	}
	free_mass(arr);
	return (1);
}

int		check_int(char *nbr)
{
	if (*nbr == '-')
		nbr++;
	while (*nbr != '\0')
		if (*nbr < '0' || *nbr++ > '9')
			return (-1);
	return (1);
}

void	check_resolution(t_head head, void *mlx)
{
	int		width;
	int		height;

	mlx_get_screen_size(mlx, &width, &height);
	if (head.vip->rw > width || head.vip->rh > height)
	{
		head.vip->rh = height;
		head.vip->rw = width;
	}
}
