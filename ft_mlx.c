/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:16:08 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/04/05 17:46:01 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int			ft_expose_hook(t_var *var)
{
//	int		i;

//	i = 0;
//	while (i < HEIGHT * LENGTH)
	{
		var->img_str[i] = 0;
		i++;
	}
///
	ft_bzero((char *)var->img_str, LENGTH * HEIGHT * (BITS_PER_PIXEL / 8));
	if (var->array->size == 1)
		ft_onlyone(var);
	else if (var->pixel == 0)
		ft_create_map(var);
	else if (var->pixel == 1)
		ft_pixel_map(var);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr, 0, 0);
	ft_menu(var);
	return (0);
}
*/
int			ft_expose_hook(t_var *var)
{
	var->img_str = (int *)(mlx_get_data_addr(var->img_ptr
				, &(var->img->bits), &var->img->length, &var->img->endian));
	if (var->array->size == 1)
		ft_onlyone(var);
	else if (var->pixel == 0)
		ft_create_map(var);
	else if (var->pixel == 1)
		ft_pixel_map(var);
	mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr, 0, 0);
	mlx_destroy_image(var->mlx_ptr, var->img_ptr);
	var->img_ptr = NULL;
	ft_menu(var);
	if (!(var->img_ptr = mlx_new_image(var->mlx_ptr, LENGTH, HEIGHT)))
		ft_error(var, NULL);
	return (0);
}

void		ft_delete_mlx(t_var *var)
{
	if (var->win_ptr != NULL)
	{
		mlx_destroy_window(var->mlx_ptr, var->win_ptr);
		var->win_ptr = NULL;
	}
	if (var->img_ptr != NULL)
	{
		mlx_destroy_image(var->mlx_ptr, var->img_ptr);
		var->img_ptr = NULL;
	}
	if (var->mlx_ptr != NULL)
		ft_memdel((void **)&var->mlx_ptr);
}

void		ft_init_mlx(t_var *var)
{
	ft_init_img(var);
	ft_init_option(var);
	if ((var->mlx_ptr = mlx_init()) == NULL)
		ft_error(var, NULL);
	if ((var->win_ptr = mlx_new_window(var->mlx_ptr, LENGTH, HEIGHT, "fdf"))
			== NULL)
		ft_error(var, NULL);
	if ((var->img_ptr = mlx_new_image(var->mlx_ptr, LENGTH, HEIGHT)) == NULL)
		ft_error(var, NULL);
	var->img_str = (int *)mlx_get_data_addr(var->img_ptr, &(var->img->bits)
	, &var->img->length, &var->img->endian);
}
