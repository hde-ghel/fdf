/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreynaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:27:24 by jreynaer          #+#    #+#             */
/*   Updated: 2019/08/04 18:42:48 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press2(int key, t_var *var)
{
	if (key == X_KEY)
	{
		if (var->no_ground == 0)
			var->no_ground = 1;
		else
			var->no_ground = 0;
	}
	else if (key == PDOWN_KEY)
	{
		if (var->offset_z > -12)
			var->offset_z -= 0.2;
	}
	else if (key == PUP_KEY)
	{
		if (var->offset_z < 12)
			var->offset_z += 0.2;
	}
	else if (key == NKPL_KEY)
		var->zoom += 0.1;
	else if (key == NKMN_KEY)
	{
		if (var->zoom > 0.2)
			var->zoom -= 0.1;
	}
}

void	key_press3(int key, t_var *var)
{
	if (key == D_KEY)
		var->offset_x += 20;
	else if (key == A_KEY)
		var->offset_x -= 20;
	else if (key == W_KEY)
		var->offset_y -= 20;
	else if (key == S_KEY)
		var->offset_y += 20;
	else if (key == UP_KEY)
	{
		if (var->projection == 1)
			var->y_angle += 0.05;
		else
			var->rot_y_angle += 0.05;
	}
	else if (key == DOWN_KEY)
	{
		if (var->projection == 1)
			var->y_angle -= 0.05;
		else
			var->rot_y_angle -= 0.05;
	}
	else if (key == NK8_KEY)
		var->rot_x_angle += 0.05;
}

void	key_press4(int key, t_var *var)
{
	if (key == E_KEY)
	{
		if (var->offset_r > 0x00000000)
		{
			var->offset_r -= 0x00050000;
			var->offset_c -= 0x00050000;
		}
	}
	else if (key == R_KEY)
	{
		if (var->offset_r < 0x00FF0000)
		{
			var->offset_r += 0x00050000;
			var->offset_c += 0x00050000;
		}
	}
	else if (key == F_KEY)
	{
		if (var->offset_g > 0x00000000)
		{
			var->offset_g -= 0x00000500;
			var->offset_c -= 0x00000500;
		}
	}
}

void	key_press5(int key, t_var *var)
{
	if (key == G_KEY)
	{
		if (var->offset_g < 0x0000FF00)
		{
			var->offset_g += 0x00000500;
			var->offset_c += 0x00000500;
		}
	}
	else if (key == V_KEY)
	{
		if (var->offset_b > 0x00000000)
		{
			var->offset_b -= 0x00000005;
			var->offset_c -= 0x00000005;
		}
	}
	else if (key == B_KEY)
	{
		if (var->offset_b < 0x000000FF)
		{
			var->offset_b += 0x00000005;
			var->offset_c += 0x00000005;
		}
	}
}

void	key_press6(int key, t_var *var)
{
	if (key == N_KEY)
	{
		if (var->cte > 0.5)
			var->cte -= 0.1;
	}
	else if (key == M_KEY)
	{
		if (var->cte < 3)
			var->cte += 0.1;
	}
	else if (key == P_KEY)
	{
		if (var->pixel == 0)
			var->pixel = 1;
		else
			var->pixel = 0;
	}
}
