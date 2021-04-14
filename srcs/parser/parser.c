/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:27:48 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

int	final_check(t_head *head, int id, int gnl)
{
	if (gnl == -1)
		return (-42);
	if (id < 0)
		return (id);
	if (head->vip->rh == -1)
		return (-823);
	if (head->vip->ratio == -0.1)
		return (-922);
	if (head->cam_count == 0)
		return (-624);
	return (1);
}

int	make_leaf(int id, char **mass, t_head *head)
{
	if (id == 8)
		return (r_parse(mass, head->vip));
	if (id == 9)
		return (a_parse(mass, head->vip, 0));
	if (id <= 5)
		return (make_obj(mass, head, id));
	if (id == 7)
		return (make_lt(mass, &head->lt));
	if (id == 6)
	{
		head->cam_count++;
		return (make_cam(mass, &head->cam));
	}
	return (id);
}

int	parser(t_head *head, int *err_line, int gnl, char *arg)
{
	int		fd;
	char	*line;
	char	**mass;
	int		id;

	fd = open(arg, O_RDONLY);
	id = 0;
	while (gnl && ((gnl = get_next_line(fd, &line)) >= 0))
	{
		(*err_line)++;
		if ((mass = ft_split(line, ' ')) == NULL)
		{
			free(line);
			return (-13);
		}
		if ((id = check_id(mass, -21)) > 0)
			id = make_leaf(id, mass, head);
		free_mass(mass);
		free(line);
		if (id < 0)
			return (id);
	}
	close(fd);
	return (final_check(head, id, gnl));
}
