/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifycone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/01 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static int	cone_direction(t_env *e, char *split)
{
	char	**dircone_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	dircone_split = ft_strsplit(split, ',');
	e->cone.dir = NULL;
	if (!(e->cone.dir = (t_dir*)malloc(sizeof(t_dir) * 4)))
		return (-1);
	while (dircone_split[++i])
	{
		if (i == 0)
			e->cone.dir->x = ft_atoi(dircone_split[i]);
		if (i == 1)
			e->cone.dir->y = ft_atoi(dircone_split[i]);
		if (i == 2)
			e->cone.dir->z = ft_atoi(dircone_split[i]);
	}
	return (0);
}

static int	cone_center(t_env *e, char *split)
{
	char	**cencone_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	cencone_split = ft_strsplit(split, ',');
	e->cone.cen = NULL;
	if (!(e->cone.cen = (t_cen*)malloc(sizeof(t_cen) * 4)))
		return (-1);
	while (cencone_split[++i])
	{
		if (i == 0)
			e->cone.cen->x = ft_atoi(cencone_split[i]);
		if (i == 1)
			e->cone.cen->y = ft_atoi(cencone_split[i]);
		if (i == 2)
			e->cone.cen->z = ft_atoi(cencone_split[i]);
	}
	return (0);
}

int	verifycone(t_env *e, char **splits)
{
	if ((e->ret_ver = howmanystrings(splits)) != 4)
		return (-1);
	if ((e->verify = ft_strstr(splits[0], "direction")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[1], "center")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[2], "angle")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[3], "amb")) == NULL)
		return (-1);
	while (splits[++e->i] != NULL)
	{
		if (e->i == 0)
			if ((e->ret_ver = cone_direction(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 1)
			if ((e->ret_ver = cone_center(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 2)
			e->cone.angle = ft_atoi(getnumber(splits[e->i]));
		if (e->i == 3)
			e->cone.ambient = ft_atoi(getnumber(splits[e->i]));
	}
	return (0);
}
