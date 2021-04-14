/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:06:55 by exenia            #+#    #+#             */
/*   Updated: 2021/01/31 01:21:08 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	create_bm_file_header(t_head *head)
{
	int						file_size;
	static unsigned char	*file_header;
	int						i;

	file_size = 14 + 40 + (head->vip->rw * head->vip->rh);
	file_header = (unsigned char*)malloc(sizeof(unsigned char ) * 14);
	if (file_header == NULL)
	{
		write(1, "Error\nMalloc error\n", 19);
		exit(-1);
	}
	i = 0;
	while (i < 14)
		file_header[i++] = 0;
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[2] = file_size;
	file_header[3] = file_size >> 8;
	file_header[4] = file_size >> 16;
	file_header[5] = file_size >> 24;
	file_header[10] = 54;
	write(head->fd, file_header, 14);
	free(file_header);
}

void	create_bm_info_header(t_head *head)
{
	static unsigned char	*info_header;
	int						i;

	info_header = (unsigned char*)malloc(sizeof(unsigned char ) * 40);
	if (info_header == NULL)
	{
		write(1, "Error\nMalloc error\n", 19);
		exit(-1);
	}
	i = 0;
	while (i < 40)
		info_header[i++] = 0;
	info_header[0] = 40;
	info_header[4] = head->vip->rw;
	info_header[5] = head->vip->rw >> 8;
	info_header[6] = head->vip->rw >> 16;
	info_header[7] = head->vip->rw >> 24;
	info_header[8] = head->vip->rh;
	info_header[9] = head->vip->rh >> 8;
	info_header[10] = head->vip->rh >> 16;
	info_header[11] = head->vip->rh >> 24;
	info_header[12] = 1;
	info_header[14] = 32;
	write(head->fd, info_header, 40);
	free(info_header);
}

void	image_to_file(t_head *head)
{
	int y;
	int len;

	len = head->vip->rw * head->img.bits_per_pixel / 8;
	y = head->vip->rh;
	while (y >= 0)
	{
		write(head->fd, (unsigned char *)(head->img.addr +
			y * head->img.line_length), len);
		y--;
	}
}

void	create_bm_image(t_head *head)
{
	head->fd = open("My_awesome_image.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0655);
	if (head->fd < 0)
	{
		write(1, "Error\nSave error\n", 17);
		exit(-1);
	}
	create_bm_file_header(head);
	create_bm_info_header(head);
	image_to_file(head);
	exit(1);
}
