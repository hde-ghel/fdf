/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceseg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:25:45 by jreynaer          #+#    #+#             */
/*   Updated: 2019/04/05 20:16:18 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tracer_pixel(int color, int x, int y, int *img_str)
{
	int		j;

	if (x > (LENGTH / 7) - 1 && x < LENGTH && y > 0 && y < HEIGHT)
	{
		j = (y * LENGTH) + x;
		if (j >= 0 && j < (LENGTH * HEIGHT))
			img_str[j] = color;
	}
}

void	init_points2(t_var *var, t_points2 *points2, int nb)
{
	points2->x0 = var->points->x1;
	points2->y0 = var->points->y1;
	if (nb == 1)
	{
		points2->x0 = LENGTH / 7;
		points2->y0 = 0;
		points2->x1 = LENGTH / 7;
		points2->y1 = HEIGHT;
	}
	else if (nb == 2)
	{
		points2->x1 = var->points->x2;
		points2->y1 = var->points->y2;
	}
	else
	{
		points2->x1 = var->points->x3;
		points2->y1 = var->points->y3;
	}
	points2->dx = abs(points2->x1 - points2->x0);
	points2->sx = points2->x0 < points2->x1 ? 1 : -1;
	points2->dy = abs(points2->y1 - points2->y0);
	points2->sy = points2->y0 < points2->y1 ? 1 : -1;
	points2->err = (points2->dx > points2->dy ? points2->dx : -points2->dy) / 2;
}

int		ft_seg1(int color, t_var *var, int nb)
{
	t_points2 *points2;

	if ((points2 = (t_points2 *)malloc(sizeof(t_points2))) == NULL)
		ft_error(var, NULL);
	init_points2(var, points2, nb);
	while (1)
	{
		ft_tracer_pixel(color, points2->x0, points2->y0, var->img_str);
		if (points2->x0 == points2->x1 && points2->y0 == points2->y1)
			break ;
		points2->e2 = points2->err;
		if (points2->e2 > -points2->dx)
		{
			points2->err -= points2->dy;
			points2->x0 += points2->sx;
		}
		if (points2->e2 < points2->dy)
		{
			points2->err += points2->dx;
			points2->y0 += points2->sy;
		}
	}
	ft_memdel((void **)&points2);
	return (0);
}
