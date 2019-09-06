/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_eight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:29:56 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/05 15:16:15 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void	reset_spec_atb(t_env *e)
{
	e->ca_atb.position = 0;
	e->ca_atb.direction = 0;
	e->ca_atb.rotation = 0;
	e->ca_atb.translation = 0;
	e->a_atb.power = 0;
	e->a_atb.color = 0;
	e->l_atb.position = 0;
	e->l_atb.intensity = 0;
	e->l_atb.rotate = 0;
	e->l_atb.translate = 0;
}

int		verify_spec_atb_light(t_env *e)
{
	if (ft_strcmp("position", e->s_tmp) == 0)
		e->l_atb.position++;
	else if (ft_strcmp("intensity", e->s_tmp) == 0)
		e->l_atb.intensity++;
	else if (ft_strcmp("rotate", e->s_tmp) == 0)
		e->l_atb.rotate++;
	else if (ft_strcmp("translate", e->s_tmp) == 0)
		e->l_atb.translate++;
	else
		return (68);
	return (0);
}

int		verify_spec_atb(t_env *e, char **split) // /! string needs to be freed before returning error message /!
{
	e->s_tmp = ft_strsub(split[0], 4, (ft_strclen(split[0], '>') - 4));
	if (e->p_spec.cam == 1)
	{
		if (ft_strcmp("position", e->s_tmp) == 0)
			e->ca_atb.position++;
		else if (ft_strcmp("direction", e->s_tmp) == 0)
			e->ca_atb.direction++;
		else
			return (62);
	}
	if (e->p_spec.amb == 1)
	{
		if (ft_strcmp("specpower", e->s_tmp) == 0)
			e->a_atb.power++;
		else if (ft_strcmp("color", e->s_tmp) == 0)
			e->a_atb.color++;
		else
			return (65);
	}
	if (e->p_spec.light >= 1)
		if ((e->ret_tmp = verify_spec_atb_light(e)) != 0)
			return (e->ret_tmp);
	free(e->s_tmp);
	e->s_tmp = NULL;
	return (0);
}

int		verify_spec_atb_partwo_light(t_env *e)
{
	if (e->l_atb.position < 1 || e->l_atb.intensity < 1)
		return (66);
	if (e->l_atb.position > 1 || e->l_atb.intensity > 1)
		return (67);
	if (e->p.status == 1)
		if (e->l_atb.rotate != 0 || e->l_atb.translate != 0)
			return (69);
	if (e->p.status == 2)
		if (e->l_atb.rotate != 1 || e->l_atb.translate != 1)
			return (70);
	return (0);
}

int		verify_spec_atb_partwo(t_env *e)
{
	if (e->p_spec.cam_cl == 1 && e->p_spec.amb_cl == 0 && e->p_spec.light == 0)
	{
		if (e->ca_atb.position < 1 || e->ca_atb.direction < 1)
			return (60);
		if (e->ca_atb.position > 1 || e->ca_atb.direction > 1)
			return (61);
	}
	else if (e->p_spec.cam_cl == 1 && e->p_spec.amb_cl == 1
		&& e->p_spec.light == 0)
	{
		if (e->a_atb.power < 1 || e->a_atb.color < 1)
			return (63);
		if (e->a_atb.power > 1 || e->a_atb.color > 1)
			return (64);
	}
	if (e->p_spec.cam_cl == 1 && e->p_spec.amb_cl == 1 && e->p_spec.light >= 1)
		if ((e->ret_tmp = verify_spec_atb_partwo_light(e)) != 0)
			return (e->ret_tmp);
	return (0);
}
