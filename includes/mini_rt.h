/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:56:32 by exenia            #+#    #+#             */
/*   Updated: 2021/02/05 13:23:30 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINI_RT_H
# define __MINI_RT_H

# define BUFFER_SIZE 10
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "mlx.h"
# include "../libft/libft.h"

typedef struct		s_obj
{
	int				id;
	int				rgb[3];
	double			xyz[3];
	double			xyz_o[3];
	double			special;
	double			height;
	struct s_obj	*next;
	double			tr[4][4];
}					t_obj;

typedef struct		s_cam
{
	double			xyz[3];
	double			xyz_o[3];
	int				fov;
	struct s_cam	*next;
	struct s_cam	*prev;

}					t_cam;

typedef struct		s_lt
{
	double			xyz[3];
	double			ratio;
	int				rgb[3];
	struct s_lt		*next;
}					t_lt;

typedef struct		s_vip
{
	double			ratio;
	int				rgb[3];
	int				rw;
	int				rh;
}					t_vip;

typedef struct		s_tmp
{
	int				id;
	int				n_rgb[3];
	double			closet_t;
	double			n[3];
	double			p[3];
	double			rev_d[3];
	double			d[3];

}					t_tmp;

typedef struct		s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_head
{
	struct s_lt		*lt;
	struct s_cam	*cam;
	struct s_obj	*obj;
	struct s_vip	*vip;
	t_tmp			tmp;
	t_data			img;
	void			*mlx;
	void			*win;
	int				fd;
	int				gnl;
	int				cam_count;
}					t_head;

typedef struct		s_eq {
	double			k1;
	double			k2;
	double			k3;
	double			t1;
	double			t2;
	double			closet_t;
}					t_eq;
/*
**PARSER FUNCTIONS --->>>
*/
void				make_linked_list(t_cam **cam);
void				cam_lstadd_front(t_cam **lst, t_cam *new);
void				lt_lstadd_front(t_lt **lst, t_lt *new);
void				obj_lstadd_front(t_obj **lst, t_obj *new);
int					check_id(char **mass, int id);
int					check_int(char *nbr);
int					check_double(char *arr);
double				ft_atof(char *s);
int					free_mass(char **mass);
int					parser(t_head *head, int *err_line, int gnl, char *arg);
int					make_rgb(int dst[3], char *mass);
int					make_xyz(double dst[3], char *mass);
int					make_vip(int id, char **mass, t_vip *vip);
int					make_cam(char **mass, t_cam **cam);
int					make_lt(char **mass, t_lt **lt);
int					make_obj(char **mass, t_head *head, int id);
void				free_head(t_head *head);
int					r_parse(char **mass, t_vip *vip);
int					a_parse(char **mass, t_vip *vip, int i);
int					treangle_parse(char **mass, t_obj *obj, int i);
int					cylindre_parse(char **mass, t_obj *obj, int i);
int					square_parse(char **mass, t_obj *obj, int i);
int					plane_parse(char **mass, t_obj *obj, int i);
int					sphere_parse(char **mass, t_obj *obj, int i);
void				error_out(int err_line, int result);
void				check_resolution(t_head head, void *mlx);
int					get_next_line(int fd, char **line);
void				square_points_compute(t_obj *obj);
/*
** VECTORS OPERATIONS --->>>
*/
double				v_dot(double v1[3], double v2[3]);
double				v_len(double v[3]);
double				*v_nbr(double k, double v[3], double v_return[3]);
void				v_add(double v1[3], double v2[3], double v_return[3]);
double				*v_substr(double v1[3], double v2[3], double v_return[3]);
void				v_normalize(double v[3]);
double				*v_cross(double v1[3], double v2[3], double v3[3]);
void				v_copy(double v1[3], double v2[3]);
/*
** INTERSECTIONS --->>>
*/
double				plane_intersection(double o[3], double d[3], t_obj *obj);
double				sphere_intersection(double *v1, double *v2, t_obj *obj);
double				treangle_intersection(double o[3], double d[3], t_obj *obj);
double				square_intersection(double o[3], double d[3], t_obj *obj);
double				cylindre_intersection(double o[3], double d[3], t_obj *obj);
double				quadric_equition(t_eq *eq);
/*
** COLOR AND LIGHT --->>>
*/
void				color_calc(t_head *head, t_tmp tmp);
void				shadow_shine(t_head *head, t_tmp tmp,
						t_lt	lt, double l[3]);
int					*compute_light(int c1[3], int c2[3], double r);
int					create_rgb(int *rgb);
/*
** MLX++ --->>>
*/
int					key_hook(int keycode, t_head *head);
int					close_win();
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				create_bm_image(t_head *head);
/*
** GENERAL --->>>
*/
t_obj				*closet_inter(double o[3], double d[3],
						double max, t_head *head);
double				closet_t_compute(double o[3], double d[3], t_obj *obj);
void				initialize(t_head *head);
void				cam_orient(t_cam *cam, double d[3]);
void				point_preparation(t_head *head, double o[3],
						double d[3], t_obj *obj);
void				mini_rt(t_head *head, int err_line, char *arg, int fd);
void				render_scene(t_head *head);
int					trace_ray(double *o, double *d, t_head *head);
#endif
