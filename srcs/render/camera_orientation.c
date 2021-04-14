/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:26:53 by exenia            #+#    #+#             */
/*   Updated: 2021/02/01 17:31:55 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	cam_orient(t_cam *cam, double d[3])
{
	double	up[3];
	double	cam_right[3];
	double	cam_up[3];
	double	rev_d[3];
	double	new_v[3];

	up[0] = 0.0;
	up[1] = 1.0;
	up[2] = 0.0;
	v_normalize(v_cross(up, cam->xyz_o, cam_right));
	v_cross(cam->xyz_o, cam_right, cam_up);
	v_nbr(-1, d, rev_d);
	new_v[0] = cam_right[0] * d[0] + cam_right[1] * d[1] + cam_right[2] * d[2];
	new_v[1] = cam_up[0] * d[0] + cam_up[1] * d[1] + cam_up[2] * d[2];
	new_v[2] = cam->xyz_o[0] * d[0] +
		cam->xyz_o[1] * d[1] + cam->xyz_o[2] * d[2];
	d[0] = new_v[0];
	d[1] = new_v[1];
	d[2] = new_v[2];
}
