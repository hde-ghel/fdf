/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:49:32 by jreynaer          #+#    #+#             */
/*   Updated: 2019/02/28 16:49:57 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_array(char *dest, t_var *var)
{
	int			i;

	var->array->size = 0;
	i = 0;
	while (dest[i])
	{
		if (ft_isdigit(dest[i]) == 1)
		{
			var->array->size++;
			while (ft_isdigit(dest[i]) == 1)
				i++;
		}
		i++;
	}
	if (var->array->col_height != 0)
		var->array->line_len = (var->array->size / var->array->col_height);
}

void	ft_init_img(t_var *var)
{
	var->img->endian = ENDIAN;
	var->img->height = HEIGHT;
	var->img->length = LENGTH;
	var->img->bits = BITS_PER_PIXEL;
}

void	ft_init_option(t_var *var)
{
	var->projection = 0;
	var->offset_x = 0;
	var->offset_y = 0;
	var->offset_z = 1;
	var->centre_x = 0;
	var->centre_y = 0;
	var->x_angle = 0;
	var->y_angle = 0.5;
	var->zoom = 1;
	var->cte = 0.5;
	var->pixel = 0;
	var->no_ground = 0;
	var->offset_c = 0x00000000;
	var->offset_r = 0x00000000;
	var->offset_g = 0x00000000;
	var->offset_b = 0x00000000;
	var->rot_x_angle = 0;
	var->rot_y_angle = 0;
	var->rot_z_angle = 0;
}

void	ft_init_height(t_var *var, int j)
{
	int			max_height;
	int			diff_height;

	max_height = MAX_Z;
	diff_height = (var->array->max_z - var->array->min_z) / var->offset_z;
	if (diff_height == 0)
		diff_height = 1;
	var->points->z1 = ((var->alt_tab[j + 1] * max_height) / diff_height);
	if (j + 2 <= var->array->size && diff_height)
		var->points->z2 = ((var->alt_tab[j + 2] * max_height) / diff_height);
	if (j + 1 + var->array->line_len <= var->array->size && diff_height)
		var->points->z3 = ((var->alt_tab[j + 1 + var->array->line_len]
					* max_height) / diff_height);
}

void	ft_init_points(t_var *var, int j)
{
	double	seglen;

	seglen = ft_seglen(var);
	ft_init_height(var, j);
	if (var->projection == 2)
		ft_conic(var, seglen, j);
	else
	{
		var->points->x1 = ((j % var->array->line_len) * seglen);
		var->points->y1 = ((j / var->array->line_len) * seglen);
		var->points->x2 = var->points->x1 + seglen;
		var->points->y2 = var->points->y1;
		var->points->x3 = var->points->x1;
		var->points->y3 = var->points->y1 + seglen;
		map_rotation(var);
		if (var->projection == 1)
			ft_true_iso(var);
		if (var->projection == 3)
			ft_para(var);
	}
}
