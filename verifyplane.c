/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifyplane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/31 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static int	plane_normal(t_env *e, char *split)
{
	char	**nor_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	nor_split = ft_strsplit(split, ',');
	e->plane.nor = NULL;
	if (!(e->plane.nor = (t_normal*)malloc(sizeof(t_normal) * 4)))
		return (-1);
	while (nor_split[++i])
	{
		if (i == 0)
			e->plane.nor->x = ft_atoi(nor_split[i]);
		if (i == 1)
			e->plane.nor->y = ft_atoi(nor_split[i]);
		if (i == 2)
			e->plane.nor->z = ft_atoi(nor_split[i]);
	}
	return (0);
}

int	verifyplane(t_env *e, char **splits)
{
	if ((e->ret_ver = howmanystrings(splits)) != 3)
		return (-1);
	if ((e->verify = ft_strstr(splits[0], "normal")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[1], "d")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[2], "mat")) == NULL)
		return (-1);
	while (splits[++e->i] != NULL)
	{
		if (e->i == 0)
			if ((e->ret_ver = plane_normal(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 1)
			e->plane.d = ft_atoi(getnumber(splits[e->i]));
		if (e->i == 2)
			e->plane.mat = ft_atoi(getnumber(splits[e->i]));
	}
	return (0);
}
