/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:37:18 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/02/28 18:46:24 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_var *var)
{
	if (key != ESC_KEY && key != NK0_KEY && key != NK1_KEY && key != NK2_KEY 
		&& key != NK3_KEY && key != NK0_KEY && key != NK1_KEY && key != NK2_KEY 
		&& key != NK3_KEY)
	{
		key_press2(key, var);
		key_press3(key, var);
		key_press4(key, var);
		key_press5(key, var);
		key_press6(key, var);
		if (key == NK7_KEY)
			var->rot_x_angle -= 0.05;
		else if (key == RIGHT_KEY)
			var->rot_z_angle += 0.05;
		else if (key == LEFT_KEY)
			var->rot_z_angle -= 0.05;
		ft_expose_hook(var);
	}
	return (0);
}

void	ft_freeall(t_var *var)
{
	if (var->mlx_ptr)
		ft_delete_mlx(var);
	if (var->alt_tab != NULL)
		ft_memdel((void **)&var->alt_tab);
	if (var)
	{
		if (var->img)
			ft_memdel((void **)&var->img);
		if (var->points)
			ft_memdel((void **)&var->points);
		if (var->array)
			ft_memdel((void **)&var->array);
		if (var->alt_tab)
			ft_memdel((void **)&var->alt_tab);
		ft_memdel((void **)&var);
	}
}

int		ft_key_hook(int key, t_var *var)
{
	if (key == ESC_KEY || key == NK0_KEY || key == NK1_KEY || key == NK2_KEY 
		|| key == NK3_KEY || key == F5_KEY)
	{
		if (key == ESC_KEY)
		{
			ft_freeall(var);
			exit(0);
		}
		if (key == NK0_KEY || key == NK1_KEY || key == NK2_KEY || key == NK3_KEY
				|| key == F5_KEY)
			ft_init_option(var);
		if (key == NK0_KEY)
			var->projection = 0;
		if (key == NK1_KEY)
			var->projection = 1;
		if (key == NK2_KEY)
			var->projection = 2;
		if (key == NK3_KEY)
			var->projection = 3;
		ft_expose_hook(var);
	}
	return (0);
}
