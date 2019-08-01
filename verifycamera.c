/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifycamera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/01 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static int	cam_position(t_env *e, char *split)
{
	char	**pos_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	pos_split = ft_strsplit(split, ',');
	e->cam.campos = NULL;
	if (!(e->cam.campos = (t_pos*)malloc(sizeof(t_pos) * 4)))
		return (-1);
	while (pos_split[++i])
	{
		if (i == 0)
			e->cam.campos->x = ft_atoi(pos_split[i]);
		if (i == 1)
			e->cam.campos->y = ft_atoi(pos_split[i]);
		if (i == 2)
			e->cam.campos->z = ft_atoi(pos_split[i]);
	}
	return (0);
}

static int	cam_direction(t_env *e, char *split)
{
	char	**dir_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	dir_split = ft_strsplit(split, ',');
	e->cam.camdir = NULL;
	if (!(e->cam.camdir = (t_dir*)malloc(sizeof(t_dir) * 4)))
		return (-1);
	while (dir_split[++i])
	{
		if (i == 0)
			e->cam.camdir->x = ft_atoi(dir_split[i]);
		if (i == 1)
			e->cam.camdir->y = ft_atoi(dir_split[i]);
		if (i == 2)
			e->cam.camdir->z = ft_atoi(dir_split[i]);
	}
	return (0);
}

int		verifycam(t_env *e, char **splits)
{
	if ((e->ret_ver = howmanystrings(splits)) != 2)
		return (-1);
	if ((e->verify = ft_strstr(splits[0], "position")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[1], "direction")) == NULL)
		return (-1);
	while (splits[++e->i] != NULL)
	{
		if (e->i == 0)
			if ((e->ret_ver = cam_position(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 1)
			if ((e->ret_ver = cam_direction(e, splits[e->i])) != 0)
				return (-1);
	}
	return (0);
}

