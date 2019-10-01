/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:09:53 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/05 17:56:26 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_centre_conic(t_var *var, double base)
{
	var->centre_x = (LENGTH / 7 * 6 / 2) - (base / 2) + LENGTH / 7;
	var->centre_y = (HEIGHT / 2) - (base / 4);
}

void		ft_centre(t_var *var)
{
	double	seglen;
	double	temp;

	seglen = ft_seglen(var);
	var->centre_x = var->array->line_len / 2 * seglen;
	var->centre_y = var->array->col_height / 2 * seglen;
	if (var->projection == 1)
	{
		temp = var->centre_x;
		var->centre_x = ((var->centre_x - var->centre_y) * cos(var->x_angle));
		var->centre_y = ((temp + var->centre_y) * sin(var->y_angle));
	}
	var->centre_x = (LENGTH / 2) - var->centre_x + LENGTH / 7;
	var->centre_y = (HEIGHT / 2) - var->centre_y;
}

double		ft_seglen(t_var *var)
{
	double		seglen;

	if (var->array->line_len >= var->array->col_height)
		seglen = (LENGTH / 2) / var->array->line_len * var->zoom;
	else
		seglen = HEIGHT / 2 / var->array->col_height * var->zoom;
	return (seglen);
}

int			ft_getcolor(int i, int j, t_var *var)
{
	if (i <= -80 || j <= -80)
		return (0x00000066 + var->offset_c);
	else if (i <= -60 || j <= -60)
		return (0x00003366 + var->offset_c);
	else if (i <= -40 || j <= -40)
		return (0x00003399 + var->offset_c);
	else if (i <= -20 || j <= -20)
		return (0x00006666 + var->offset_c);
	else if (i <= 0 && j <= 0 && var->no_ground == 0)
		return (0x00009999 + var->offset_c);
	else if (i <= 0 && j <= 0 && var->no_ground == 1)
		return (0x00000000);
	else if (i >= 80 || j >= 80)
		return (0x00663300 + var->offset_c);
	else if (i >= 60 || j >= 60)
		return (0x00994C00 + var->offset_c);
	else if (i >= 40 || j >= 40)
		return (0x00CC6600 + var->offset_c);
	else if (i >= 20 || j >= 20)
		return (0x00F9BA7B + var->offset_c);
	else
		return (0x00FFCC99 + var->offset_c);
}

int			main(int ac, char **av)
{
	char	*dest;
	t_var	*var;

	if (ac != 2)
		return (0);
	if (!(var = (t_var *)malloc(sizeof(t_var))))
		ft_error(NULL, NULL);
	if (!(var->img = (t_img *)malloc(sizeof(t_img))))
		ft_error(var, NULL);
	if (!(var->array = (t_array *)malloc(sizeof(t_array))))
		ft_error(var, NULL);
	if ((dest = ft_read(av[1], var)) == NULL)
		ft_error(var, NULL);
	ft_init_array(dest, var);
	if (!(var->alt_tab = (int *)malloc(sizeof(int) * var->array->size + 4)))
		ft_error(var, dest);
	ft_init_alt_tab(dest, var);
	ft_init_mlx(var);
	mlx_hook(var->win_ptr, 2, 1, key_press, var);
	mlx_key_hook(var->win_ptr, ft_key_hook, var);
	mlx_expose_hook(var->win_ptr, ft_expose_hook, var);
	mlx_loop(var->mlx_ptr);
}
