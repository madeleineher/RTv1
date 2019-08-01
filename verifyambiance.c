/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifyambiance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/01 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

static int	amb_diffusion(t_env *e, char *split)
{
	char	**diff_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	diff_split = ft_strsplit(split, ',');
	e->amb.diff = NULL;
	if (!(e->amb.diff = (t_diff*)malloc(sizeof(t_diff) * 4)))
		return (-1);
	while (diff_split[++i])
	{
		if (i == 0)
			e->amb.diff->x = ft_atoi(diff_split[i]);
		if (i == 1)
			e->amb.diff->y = ft_atoi(diff_split[i]);
		if (i == 2)
			e->amb.diff->z = ft_atoi(diff_split[i]);
	}
	return (0);
}

static int	amb_reflection(t_env *e, char *split)
{
	char	**ref_split;
	int	i = -1;

	while (!ft_isdigit(*split))
		split++;
	ref_split = ft_strsplit(split, ',');
	e->amb.ref = NULL;
	if (!(e->amb.ref = (t_ref*)malloc(sizeof(t_ref) * 4)))
		return (-1);
	while (ref_split[++i])
	{
		if (i == 0)
			e->amb.ref->x = ft_atoi(ref_split[i]);
		if (i == 1)
			e->amb.ref->y = ft_atoi(ref_split[i]);
		if (i == 2)
			e->amb.ref->z = ft_atoi(ref_split[i]);
	}
	return (0);
}

int	verifyamb(t_env *e, char **splits)
{
	if ((e->ret_ver = howmanystrings(splits)) != 4)
		return (-1);
	if ((e->verify = ft_strstr(splits[0], "diffusion")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[1], "reflection")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[2], "specvalue")) == NULL)
		return (-1);
	if ((e->verify = ft_strstr(splits[3], "specpower")) == NULL)
		return (-1);
	while (splits[++e->i] != NULL)
	{
		if (e->i == 0)
			if ((e->ret_ver = amb_diffusion(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 1)
			if ((e->ret_ver = amb_reflection(e, splits[e->i])) != 0)
				return (-1);
		if (e->i == 2)
			e->amb.specvalue = ft_atoi(getnumber(splits[e->i]));
		if (e->i == 3)
			e->amb.specpower = ft_atoi(getnumber(splits[e->i]));
	}
	return (0);
}
