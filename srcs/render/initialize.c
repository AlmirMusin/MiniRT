/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:36:17 by exenia            #+#    #+#             */
/*   Updated: 2021/01/30 23:53:39 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

double	*canvas_to_viewport(double x, double y, t_head *head, double *d)
{
	double t;

	t = 2 * tan(head->cam->fov * M_PI / 360);
	d[0] = x / head->vip->rh * t;
	d[1] = y / head->vip->rh * t;
	d[2] = 1.0;
	return (d);
}

void	render_scene(t_head *head)
{
	int		x;
	int		y;
	int		color;
	double	d[3];

	x = -head->vip->rw / 2;
	while (x < head->vip->rw / 2)
	{
		y = -head->vip->rh / 2;
		while (y < head->vip->rh / 2)
		{
			canvas_to_viewport(x, y, head, d);
			cam_orient(head->cam, d);
			color = trace_ray(head->cam->xyz, d, head);
			my_mlx_pixel_put(&head->img, head->vip->rw / 2 + x,
				head->vip->rh / 2 - y - 1, color);
			y++;
		}
		x++;
	}
	if (head->fd == 1)
		create_bm_image(head);
	mlx_put_image_to_window(head->mlx, head->win, head->img.img, 0, 0);
}

void	initialize(t_head *head)
{
	head->mlx = mlx_init();
	check_resolution(*head, head->mlx);
	if (head->fd == -1)
	{
		head->win = mlx_new_window(head->mlx,
			head->vip->rw, head->vip->rh, "Hello world!");
		mlx_key_hook(head->win, key_hook, head);
		mlx_hook(head->win, 17, 1L << 0, close_win, head);
	}
	head->img.img = mlx_new_image(head->mlx, head->vip->rw, head->vip->rh);
	head->img.addr = mlx_get_data_addr(head->img.img, &head->img.bits_per_pixel,
		&head->img.line_length, &head->img.endian);
	render_scene(head);
	mlx_loop(head->mlx);
}
