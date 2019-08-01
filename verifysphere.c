/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifysphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/31 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static int	sphere_cen(t_env *e, char *split)
{
	char	**censphere_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	censphere_split = ft_strsplit(split, ',');
	e->sphere.cen = NULL;
	if (!(e->sphere.cen = (t_cen*)malloc(sizeof(t_cen) * 4)))
		return (-1);
	while (censphere_split[++i])
	{
		if (i == 0)
			e->sphere.cen->x = ft_atoi(censphere_split[i]);
		if (i == 1)
			e->sphere.cen->y = ft_atoi(censphere_split[i]);
		if (i == 2)
			e->sphere.cen->z = ft_atoi(censphere_split[i]);
	}
	return (0);
}

int	verifysphere(t_env *e, char **splits)
{
	if ((e->ret_ver = howmanystrings(splits)) != 3)
		return (-1);
	if ((e->verify = ft_strstr(splits[0], "center")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[1], "radius")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[2], "amb")) == NULL)
		return (-1);
	while (splits[++e->i] != NULL)
	{
		if (e->i == 0)
			if ((e->ret_ver = sphere_cen(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 1)
			e->sphere.radius = ft_atoi(getnumber(splits[e->i]));
		if (e->i == 2)
			e->sphere.ambient = ft_atoi(getnumber(splits[e->i]));
	}
	return (0);
}
