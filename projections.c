/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:58:27 by jreynaer          #+#    #+#             */
/*   Updated: 2019/02/21 15:57:42 by jreynaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_getdy(t_var *var, int j, double side)
{
	int			dy1;
	int			floor;

	floor = (var->array->col_height) - (j / var->array->line_len) - 1;
	if (floor != 0)
	{
		if (floor == var->array->col_height)
			var->points->dy = 0;
		else
			var->points->dy = (side - ((((2 * side * floor)
					/ (3 * (var->array->col_height - 1)))))) * var->zoom;
		if (floor > 1)
			dy1 = (side - ((((2 * side * (floor - 1))
					/ (3 * (var->array->col_height - 1)))))) * var->zoom;
		if (floor == 1)
			dy1 = side * var->zoom;
	}
	else
	{
		var->points->dy = side * var->zoom;
		dy1 = 0;
	}
	return (dy1);
}

void	ft_point3(t_var *var, double dx1, double dy1, int j)
{
	int		seglen;
	double	seg;

	seglen = ft_seglen(var);
	seglen *= 1.5;
	seg = ((((var->array->line_len - 1) * seglen)
				- (2 * dx1)) / (var->array->line_len - 1));
	var->points->x3 = dx1 + ((j + var->array->line_len) %
			var->array->line_len) * seg + var->centre_x
		+ var->offset_x;
	var->points->y3 = dy1 - (var->points->z3 * var->zoom) + var->centre_y
		+ (var->centre_y / 4) + var->offset_y;
}

void	ft_conic(t_var *var, int seglen, int j)
{
	double	seg;
	double	dx1;
	double	dy1;

	seglen *= 1.5;
	dy1 = ft_getdy(var, j, ((var->array->line_len - 1) * seglen / 3));
	ft_centre_conic(var, (var->array->line_len - 1) * seglen);
	var->points->dx = (((var->array->line_len - 1) *
				seglen / 3) - var->points->dy);
	dx1 = (((var->array->line_len - 1) * seglen / 3) - dy1);
	seg = ((((var->array->line_len - 1) * seglen)
				- (2 * var->points->dx)) / (var->array->line_len - 1));
	var->points->x1 = var->points->dx + (j % var->array->line_len)
		* seg + var->centre_x + var->offset_x;
	var->points->y1 = (var->points->dy) - (var->points->z1 * var->zoom)
		+ var->centre_y + (var->centre_y / 4) + var->offset_y;
	var->points->x2 = var->points->x1 + seg;
	var->points->y2 = (var->points->dy) - (var->points->z2 * var->zoom)
		+ var->centre_y + (var->centre_y / 4) + var->offset_y;
	if ((j + var->array->line_len) < var->array->size)
		ft_point3(var, dx1, dy1, j);
}

void	ft_true_iso(t_var *var)
{
	double	temp;

	temp = var->points->x1;
	var->points->x1 = ((var->points->x1 - var->points->y1) *
			cos(var->x_angle)) + var->offset_x + var->centre_x;
	var->points->y1 = (((temp + var->points->y1) * sin(var->y_angle))
			- (var->points->z1 * var->zoom)) + var->offset_y + var->centre_y;
	temp = var->points->x2;
	var->points->x2 = ((var->points->x2 - var->points->y2) *
			cos(var->x_angle)) + var->offset_x + var->centre_x;
	var->points->y2 = (((temp + var->points->y2) * sin(var->y_angle))
			- (var->points->z2 * var->zoom)) + var->offset_y + var->centre_y;
	temp = var->points->x3;
	var->points->x3 = ((var->points->x3 - var->points->y3) *
			cos(var->x_angle)) + var->offset_x + var->centre_x;
	var->points->y3 = (((temp + var->points->y3) * sin(var->y_angle))
			- (var->points->z3 * var->zoom)) + var->offset_y + var->centre_y;
}

void	ft_para(t_var *var)
{
	var->points->x1 += var->cte * (var->points->z1 * var->zoom) * -1;
	var->points->y1 += var->cte / 2 * (var->points->z1 * var->zoom) * -1;
	var->points->x2 += var->cte * (var->points->z2 * var->zoom) * -1;
	var->points->y2 += var->cte / 2 * (var->points->z2 * var->zoom) * -1;
	var->points->x3 += var->cte * (var->points->z3 * var->zoom) * -1;
	var->points->y3 += var->cte / 2 * (var->points->z3 * var->zoom) * -1;
}
