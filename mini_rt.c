/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:28:59 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 19:32:03 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/mini_rt.h"

t_vip	*new_vip(void)
{
	t_vip	*vip;

	vip = malloc(sizeof(t_vip));
	vip->ratio = -0.1;
	vip->rw = -1;
	vip->rh = -1;
	return (vip);
}

t_head	*new_head(t_vip *vip, t_cam *cam, t_lt *lt, t_obj *obj)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->cam = cam;
	head->lt = lt;
	head->obj = obj;
	head->vip = vip;
	head->gnl = -1;
	head->cam_count = 0;
	return (head);
}

void	mini_rt(t_head *head, int err_line, char *arg, int fd)
{
	t_vip	*vip;
	t_cam	*head_cam;
	t_lt	*head_lt;
	t_obj	*head_obj;
	int		res;

	head_cam = (t_cam*)malloc(sizeof(t_cam));
	head_lt = NULL;
	head_obj = NULL;
	res = -13;
	vip = new_vip();
	head = new_head(vip, head_cam, head_lt, head_obj);
	head->fd = fd;
	if (head == NULL || vip == NULL || head_cam == NULL ||
		(res = parser(head, &err_line, head->gnl, arg)) < 0)
	{
		error_out(err_line, res);
		free_head(head);
		exit(-1);
	}
	make_linked_list(&head->cam);
	initialize(head);
	free_head(head);
}

int		check_arguments(int ac, char **av)
{
	char	*s;
	char	*strn;

	s = ".rt";
	if (ac > 3 || ac < 2 || (ac == 2 && !ft_strncmp(av[1], "--save", 7)))
	{
		write(1, "Error\ninvalid number of input arguments\n", 41);
		return (0);
	}
	strn = ft_strnstr(av[ac - 1], s, ft_strlen(av[ac - 1]));
	if (strn == NULL && write(1, "Error\ninvalid scene file extention\n", 34))
		return (0);
	if (ft_strncmp(strn, s, 4))
	{
		write(1, "Error\ninvalid scene file extention\n", 34);
		return (0);
	}
	if (ac == 3 && ft_strncmp(av[1], "--save", 7) && write(1, "Error\n", 6))
	{
		write(1, "invalid second argument, it must be \"--save\"\n", 45);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_head	*head;
	int		err_line;
	int		fd;

	err_line = 0;
	head = NULL;
	fd = -1;
	if (!check_arguments(argc, argv))
		return (-1);
	if (argc == 3)
		fd = 1;
	mini_rt(head, err_line, argv[argc - 1], fd);
	return (0);
}
