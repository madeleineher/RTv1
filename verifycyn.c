/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifycyn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/31 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static int	cyn_direction(t_env *e, char *split)
{
	char	**cencyn_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	cencyn_split = ft_strsplit(split, ',');
	e->cyn.dir = NULL;
	if (!(e->cyn.dir = (t_dir*)malloc(sizeof(t_dir) * 4)))
		return (-1);
	while (cencyn_split[++i])
	{
		if (i == 0)
			e->cyn.dir->x = ft_atoi(cencyn_split[i]);
		if (i == 1)
			e->cyn.dir->y = ft_atoi(cencyn_split[i]);
		if (i == 2)
			e->cyn.dir->z = ft_atoi(cencyn_split[i]);
	}
	return (0);
}

int	verifycyn(t_env *e, char **splits)
{
	if ((e->ret_ver = howmanystrings(splits)) != 4)
		return (-1);
	if ((e->verify = ft_strstr(splits[0], "direction")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[1], "axis")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[2], "radius")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[3], "amb")) == NULL)
		return (-1);
	while (splits[++e->i] != NULL)
	{
		if (e->i == 0)
			if ((e->ret_ver = cyn_direction(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 1)
			e->cyn.axis = ft_atoi(getnumber(splits[e->i]));
		if (e->i == 2)
			e->cyn.radius = ft_atoi(getnumber(splits[e->i]));
		if (e->i == 3)
			e->cyn.ambient = ft_atoi(getnumber(splits[e->i]));
	}
	return (0);
}
