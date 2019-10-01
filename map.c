/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:56:08 by jreynaer          #+#    #+#             */
/*   Updated: 2019/04/18 16:51:33 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_map(t_var *var)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	if (!(var->points = (t_points *)malloc(sizeof(t_points))))
		ft_error(var, NULL);
	ft_centre(var);
	while (j < var->array->size)
	{
		ft_init_points(var, j);
		color = ft_getcolor(var->points->z1, var->points->z2, var);
		if ((j + 1) % var->array->line_len)
			ft_seg1(color, var, 2);
		color = ft_getcolor(var->points->z1, var->points->z3, var);
		if ((var->array->size - j) > var->array->line_len)
			ft_seg1(color, var, 3);
		j++;
	}
	ft_seg1(MENU_COLOR, var, 1);
}

void	ft_onlyone(t_var *var)
{
	if (!(var->points = (t_points *)malloc(sizeof(t_points))))
		ft_error(var, NULL);
	ft_tracer_pixel(0x00FF0000, (LENGTH / 2) + var->offset_x, (HEIGHT / 2)
			+ var->offset_y, var->img_str);
	ft_seg1(MENU_COLOR, var, 1);
}

void	ft_pixel_map(t_var *var)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	if (!(var->points = (t_points *)malloc(sizeof(t_points))))
		ft_error(var, NULL);
	while (j++ < var->array->size)
	{
		ft_init_points(var, j);
		color = ft_getcolor(var->points->z1, var->points->z2, var);
		if ((j + 1) % var->array->line_len)
		{
			ft_tracer_pixel(color,
					var->points->x1, var->points->y1, var->img_str);
			ft_tracer_pixel(color,
					var->points->x2, var->points->y2, var->img_str);
		}
		color = ft_getcolor(var->points->z1, var->points->z3, var);
		if ((var->array->size - j) > var->array->line_len)
			ft_tracer_pixel(color,
					var->points->x3, var->points->y3, var->img_str);
	}
	ft_seg1(MENU_COLOR, var, 1);
}

void	ft_init_alt_tab(char *dest, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] == ' ' || dest[i] == '-')
		i++;
	var->alt_tab[j] = ft_atoi(&dest[i]);
	var->array->min_z = var->alt_tab[j];
	var->array->max_z = var->alt_tab[j];
	while (ft_isdigit(dest[i] == 1) || dest[i] == '-')
		i++;
	while (j++ < var->array->size)
	{
		while (dest[i] == ' ')
			i++;
		var->alt_tab[j] = ft_atoi(&dest[i]);
		if (var->alt_tab[j] > var->array->max_z)
			var->array->max_z = var->alt_tab[j];
		if (var->alt_tab[j] < var->array->min_z)
			var->array->min_z = var->alt_tab[j];
		while ((dest[i] >= '0' && dest[i] <= '9') || dest[i] == '-')
			i++;
	}
	ft_strdel(&dest);
}
