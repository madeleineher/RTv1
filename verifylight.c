/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifylight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/01 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static int	light_position(t_env *e, char *split)
{
	char	**li_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	li_split = ft_strsplit(split, ',');
	e->light.lipos = NULL;
	if (!(e->light.lipos = (t_pos*)malloc(sizeof(t_pos) * 4)))
		return (-1);
	while (li_split[++i])
	{
		if (i == 0)
			e->light.lipos->x = ft_atoi(li_split[i]);
		if (i == 1)
			e->light.lipos->y = ft_atoi(li_split[i]);
		if (i == 2)
			e->light.lipos->z = ft_atoi(li_split[i]);
	}
	return (0);
}

static int	light_intensity(t_env *e, char *split)
{
	char	**li_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	li_split = ft_strsplit(split, ',');
	e->light.inten = NULL;
	if (!(e->light.inten = (t_int*)malloc(sizeof(t_int) * 4)))
		return (-1);
	while (li_split[++i])
	{
		if (i == 0)
			e->light.inten->x = ft_atoi(li_split[i]);
		if (i == 1)
			e->light.inten->y = ft_atoi(li_split[i]);
		if (i == 2)
			e->light.inten->z = ft_atoi(li_split[i]);
	}
	return (0);
}

int	verifylight(t_env *e, char **splits)
{
	if ((e->ret_ver = howmanystrings(splits)) != 2)
		return (-1);
	if ((e->verify = ft_strstr(splits[0], "position")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[1], "intensity")) == NULL)
		return (-1);
	while (splits[++e->i] != NULL)
	{
		if (e->i == 0)
			if ((e->ret_ver = light_position(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 1)
			if ((e->ret_ver = light_intensity(e, splits[e->i])) != 0)
				return (-1);
	}
	return (0);
}


