/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:14 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	make_error_tail(char **error)
{
	error[0] = "invalid number of parametres\n";
	error[1] = "invalid position coordinates\n";
	error[2] = "invalid rgb\n";
	error[3] = "invalid orientation vector\n";
	error[4] = "invalid first point coordinates\n";
	error[5] = "invalid second point coordinates\n";
	error[6] = "invalid third point coordinates\n";
	error[7] = "invalid fov\n";
	error[8] = "invalid sphere radius value\n";
	error[9] = "invalid square side size\n";
	error[10] = "invalid diameter value\n";
	error[11] = "invalid height value\n";
	error[12] = "invalid light ratio value\n";
	error[13] = "malloc error\n";
	error[15] = "malloc error\n";
	error[16] = "malloc error\n";
	error[17] = "malloc error\n";
	error[18] = "malloc error\n";
	error[19] = "invalid resolution value(s)\n";
	error[20] = "multiple identfier\n";
	error[21] = "invalid identifier\n";
	error[22] = "expected ambient light\n";
	error[23] = "expected resolution of screen\n";
	error[24] = "there are no cameras\n";
}

void	make_error_head(char **id)
{
	id[0] = " ";
	id[1] = " sphere: ";
	id[2] = " plane: ";
	id[3] = " square: ";
	id[4] = " cylindre: ";
	id[5] = " treangle: ";
	id[6] = " camera: ";
	id[7] = " light: ";
	id[8] = " resolution: ";
	id[9] = " ambient light: ";
}

void	error_out(int err_line, int result)
{
	char *error[24];
	char *id[10];
	char *err_line_ch;

	write(1, "Error\n", 6);
	if (result == -42)
	{
		write(1, "Something went  wrong  while reading file ", 42);
		write(1, "or file is not exist\n", 21);
		return ;
	}
	make_error_head(id);
	make_error_tail(error);
	result *= -1;
	err_line_ch = ft_itoa(err_line);
	write(1, "in line ", 8);
	write(1, err_line_ch, ft_strlen(err_line_ch));
	write(1, id[result / 100], ft_strlen(id[result / 100]));
	write(1, error[result % 100], ft_strlen(error[result % 100]));
	free(err_line_ch);
}
