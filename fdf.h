/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:17:19 by jreynaer          #+#    #+#             */
/*   Updated: 2019/05/25 17:13:17 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "Libft/libft.h"
# include "keycode.h"
# include "minilibx_macos/mlx.h"

# define ENDIAN 1
# define LENGTH 1600
# define HEIGHT 900
# define BITS_PER_PIXEL 8
# define MAX_Z 100
# define MENU_COLOR 0x0032CD32
# define MENU_COLOR_2 0x00FFFFFF

typedef struct	s_img
{
	int			endian;
	int			bits;
	int			height;
	int			length;
}				t_img;
typedef struct	s_points
{
	double		dx;
	double		dy;
	double		x1;
	double		y1;
	double		z1;
	double		x2;
	double		y2;
	double		z2;
	double		x3;
	double		y3;
	double		z3;
}				t_points;
typedef struct	s_points2
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_points2;
typedef struct	s_array
{
	int			line_len;
	int			col_height;
	int			size;
	int			min_z;
	int			max_z;
}				t_array;
typedef	struct	s_var
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_str;
	int			*alt_tab;
	int			offset_x;
	int			offset_y;
	double		offset_z;
	double		centre_x;
	double		centre_y;
	double		x_angle;
	double		y_angle;
	double		zoom;
	int			projection;
	int			pixel;
	int			no_ground;
	int			fd;
	double		cte;
	int			offset_c;
	int			offset_r;
	int			offset_g;
	int			offset_b;

	double		rot_x_angle;
	double		rot_y_angle;
	double		rot_z_angle;

	t_img		*img;
	t_points	*points;
	t_array		*array;
}				t_var;

void			ft_centre_conic(t_var *var, double side);
void			ft_conic(t_var *var, int seglen, int j);
void			ft_true_iso(t_var *var);
int				ft_getcolor(int i, int j, t_var *var);
void			ft_init_alt_tab(char *dest, t_var *var);
void			ft_true_iso(t_var *var);
void			ft_centre(t_var *var);
void			ft_conic(t_var *var, int seglen, int j);
void			ft_init_points(t_var *var, int j);
void			ft_init_height(t_var *var, int j);
void			ft_init_option(t_var *var);
void			ft_init_img(t_var *var);
void			ft_init_array(char *dest, t_var *var);
int				ft_seg1(int color, t_var *var, int nb);
void			ft_tracer_pixel(int color, int x, int y, int *img_str);
char			*ft_read(char *input, t_var *var);
void			ft_create_map(t_var *var);
int				ft_expose_hook(t_var *var);
int				ft_key_hook(int	key, t_var *var);
int				key_press(int key, t_var *var);
void			key_press2(int key, t_var *var);
void			key_press3(int key, t_var *var);
void			key_press4(int key, t_var *var);
void			key_press5(int key, t_var *var);
void			key_press6(int key, t_var *var);
double			ft_seglen(t_var *var);
void			ft_para(t_var *var);
void			ft_pixel_map(t_var *var);
void			ft_menu(t_var *var);
void			map_rotation(t_var *var);
void			y_rotate(t_var *var);
void			ft_error(t_var *var, char *s1);
void			ft_freeall(t_var *var);
void			ft_init_mlx(t_var *var);
void			ft_delete_mlx(t_var *var);
void			ft_onlyone(t_var *var);
#endif
