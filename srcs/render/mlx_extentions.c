/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_extentions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:30:18 by exenia            #+#    #+#             */
/*   Updated: 2021/01/31 01:16:50 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		close_win(void)
{
	exit(0);
}

int		key_hook(int keycode, t_head *head)
{
	if (keycode == 53)
	{
		mlx_clear_window(head->mlx, head->win);
		mlx_destroy_window(head->mlx, head->win);
		exit(0);
	}
	if (keycode == 124)
	{
		head->cam = head->cam->next;
		mlx_clear_window(head->mlx, head->win);
		render_scene(head);
	}
	if (keycode == 123)
	{
		head->cam = head->cam->prev;
		mlx_clear_window(head->mlx, head->win);
		render_scene(head);
	}
	return (keycode);
}
