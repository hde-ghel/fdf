/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:28:51 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/02/28 18:53:43 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		x_rotation(t_var *var, int centre_x)
{
	var->points->x1 = (var->points->x1 - centre_x) * cos(var->rot_x_angle) +
		(var->points->z1 * var->zoom) * sin(var->rot_x_angle) + centre_x;
	var->points->x2 = (var->points->x2 - centre_x) * cos(var->rot_x_angle) +
		(var->points->z2 * var->zoom) * sin(var->rot_x_angle) + centre_x;
	var->points->x3 = (var->points->x3 - centre_x) * cos(var->rot_x_angle) +
		(var->points->z3 * var->zoom) * sin(var->rot_x_angle) + centre_x;
}

void		y_rotation(t_var *var, int centre_y)
{
	var->points->y1 = (var->points->y1 - centre_y) * cos(var->rot_y_angle) -
		(var->points->z1 * var->zoom) * sin(var->rot_y_angle) + centre_y;
	var->points->y2 = (var->points->y2 - centre_y) * cos(var->rot_y_angle) -
		(var->points->z2 * var->zoom) * sin(var->rot_y_angle) + centre_y;
	var->points->y3 = (var->points->y3 - centre_y) * cos(var->rot_y_angle) -
		(var->points->z3 * var->zoom) * sin(var->rot_y_angle) + centre_y;
}

void		z_rotation(t_var *var, int centre_x, int centre_y)
{
	double	delta_x;
	double	delta_y;

	delta_x = var->points->x1 - centre_x;
	delta_y = var->points->y1 - centre_y;
	var->points->x1 = delta_x * cos(var->rot_z_angle) + delta_y *
		sin(var->rot_z_angle) + centre_x;
	var->points->y1 = -delta_x * sin(var->rot_z_angle) + delta_y *
		cos(var->rot_z_angle) + centre_y;
	delta_x = var->points->x2 - centre_x;
	delta_y = var->points->y2 - centre_y;
	var->points->x2 = delta_x * cos(var->rot_z_angle) + delta_y *
		sin(var->rot_z_angle) + centre_x;
	var->points->y2 = -delta_x * sin(var->rot_z_angle) + delta_y *
		cos(var->rot_z_angle) + centre_y;
	delta_x = var->points->x3 - centre_x;
	delta_y = var->points->y3 - centre_y;
	var->points->x3 = delta_x * cos(var->rot_z_angle) + delta_y *
		sin(var->rot_z_angle) + centre_x;
	var->points->y3 = -delta_x * sin(var->rot_z_angle) + delta_y *
		cos(var->rot_z_angle) + centre_y;
}

void		map_rotation(t_var *var)
{
	double	centre_x;
	double	centre_y;

	centre_x = var->array->line_len / 2 * ft_seglen(var);
	centre_y = var->array->col_height / 2 * ft_seglen(var);
	z_rotation(var, centre_x, centre_y);
	y_rotation(var, centre_y);
	x_rotation(var, centre_x);
	if (var->projection == 0 || var->projection == 3)
	{
		var->points->x1 += var->offset_x + var->centre_x;
		var->points->x2 += var->offset_x + var->centre_x;
		var->points->x3 += var->offset_x + var->centre_x;
		var->points->y1 += var->offset_y + var->centre_y;
		var->points->y2 += var->offset_y + var->centre_y;
		var->points->y3 += var->offset_y + var->centre_y;
	}
}
