/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:15:45 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/02/19 21:31:23 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_part2(t_var *var)
{
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 260, MENU_COLOR_2, "P   : Segment / Point");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 280, MENU_COLOR_2, "PDOWN | PUP : Height");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 300, MENU_COLOR_2, "    - | +   : Zoom");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 320, MENU_COLOR, "Color :");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			25, 340, 0X00FF0000, "E | R : Red");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			25, 360, MENU_COLOR, "F | G : Green");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			25, 380, 0x000000FF, "V | B : Blue");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 410, MENU_COLOR, "Move map :    W");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 435, MENU_COLOR, "           A  S  D");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 460, MENU_COLOR, "Map rotation : ^");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 480, MENU_COLOR, "            <  v  >");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			1260, 875, MENU_COLOR, "POWERED BY JREYNAER && HDE-GHEL");
}

void	menu_basic_map(t_var *var)
{
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			5, 20, MENU_COLOR, "PROJECTION :");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 50, 0x00FFFFFF, "0 : Flat map");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 70, 0x000080FF, "1 : Iso");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 90, 0x00FF00FF, "2 : Conic");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 110, 0x00FF8000, "3 : Parallel");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			5, 170, MENU_COLOR, "CONTROLS :");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 200, MENU_COLOR_2, "F5  : reset");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 220, MENU_COLOR_2, "ESC : Close");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 240, MENU_COLOR_2, "X   : Hide ground 0");
	menu_part2(var);
}

void	menu_para(t_var *var)
{
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			5, 510, MENU_COLOR, "CONTROLS : Parallel");
	mlx_string_put(var->mlx_ptr, var->win_ptr,
			15, 530, MENU_COLOR, "N | M : Angle");
}

void	ft_menu(t_var *var)
{
	menu_basic_map(var);
	if (var->projection == 3)
		menu_para(var);
}
