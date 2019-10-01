/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:12:26 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/02/26 14:31:42 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(t_var *var, char *s1)
{
	if (var->mlx_ptr)
		ft_delete_mlx(var);
	if (var)
	{
		if (var->img)
			ft_memdel((void **)&var->img);
		if (var->array)
			ft_memdel((void **)&var->array);
		if (var->points)
			ft_memdel((void **)&var->points);
		ft_memdel((void **)&var);
	}
	if (var->alt_tab != NULL)
		ft_memdel((void **)&var->alt_tab);
	if (s1 != NULL)
		ft_strdel(&s1);
	ft_putstr("error");
	exit(-1);
}

int		ft_len(char *s)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		while (s[i] && (s[i] > '9' || s[i] < '0'))
			i++;
	}
	return (res);
}

int		ft_checkmap(int first, char *line)
{
	int		i;

	i = 0;
	if (ft_len(line) != first)
		return (-1);
	while (line[i])
	{
		if (line[i] && line[i] != ' ' && line[i] != '-'
				&& (line[i] > '9' || line[i] < '0'))
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_read(char *input, t_var *var)
{
	int		first;
	char	*line;
	char	*temp;

	first = 0;
	if (!(temp = ft_strnew(0)))
		ft_error(var, NULL);
	var->array->col_height = 0;
	if ((var->fd = open(input, O_RDONLY)) == -1)
		ft_error(var, temp);
	while (get_next_line(var->fd, &line) == 1)
	{
		first = first == 0 ? ft_len(line) : first;
		if ((line && ft_checkmap(first, line)) || (temp = ft_strjoin_free(temp,
				line, 3)) == NULL || (temp = ft_strjoin_free(temp, " ",
					1)) == NULL)
			ft_error(var, temp);
		var->array->col_height++;
		if ((first * var->array->col_height) > 300000)
			ft_error(var, temp);
	}
	if (!first)
		ft_error(var, temp);
	close(var->fd);
	return (temp);
}
