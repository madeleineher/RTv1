/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:23:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/03 12:52:23 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		shapevocab_checker_shpere(t_env *e)
{
	if (ft_strcmp("radius", e->s_tmp) == 0)
		e->s_atb.radius++;
	else if (ft_strcmp("center", e->s_tmp) == 0)
		e->s_atb.center++;
	else if (ft_strcmp("diffusion", e->s_tmp) == 0)
		e->s_atb.diffusion++;
	else if (ft_strcmp("reflection", e->s_tmp) == 0)
		e->s_atb.reflection++;
	else if (ft_strcmp("specvalue", e->s_tmp) == 0)
		e->s_atb.specvalue++;
	else if (ft_strcmp("specpower", e->s_tmp) == 0)
		e->s_atb.specpower++;
	else if (ft_strcmp("rotate", e->s_tmp) == 0)
		e->s_atb.rotate++;
	else if (ft_strcmp("translate", e->s_tmp) == 0)
		e->s_atb.translate++;
	else
		return (55);
	return (0);
}

int		shapevocab_checker_cone(t_env *e)
{
	if (ft_strcmp("radius", e->s_tmp) == 0)
		e->c_atb.radius++;
	else if (ft_strcmp("center", e->s_tmp) == 0)
		e->c_atb.center++;
	else if (ft_strcmp("diffusion", e->s_tmp) == 0)
		e->c_atb.diffusion++;
	else if (ft_strcmp("reflection", e->s_tmp) == 0)
		e->c_atb.reflection++;
	else if (ft_strcmp("specvalue", e->s_tmp) == 0)
		e->c_atb.specvalue++;
	else if (ft_strcmp("specpower", e->s_tmp) == 0)
		e->c_atb.specpower++;
	else if (ft_strcmp("angle", e->s_tmp) == 0)
		e->c_atb.angle++;
	else if (ft_strcmp("rotate", e->s_tmp) == 0)
		e->c_atb.rotate++;
	else if (ft_strcmp("translate", e->s_tmp) == 0)
		e->c_atb.translate++;
	else if (ft_strcmp("direction", e->s_tmp) == 0)
		e->c_atb.direction++;
	else
		return (56);
	return (0);
}

int		shapevocab_checker_cyn(t_env *e)
{
	if (ft_strcmp("radius", e->s_tmp) == 0)
		e->y_atb.radius++;
	else if (ft_strcmp("center", e->s_tmp) == 0)
		e->y_atb.center++;
	else if (ft_strcmp("diffusion", e->s_tmp) == 0)
		e->y_atb.diffusion++;
	else if (ft_strcmp("reflection", e->s_tmp) == 0)
		e->y_atb.reflection++;
	else if (ft_strcmp("specvalue", e->s_tmp) == 0)
		e->y_atb.specvalue++;
	else if (ft_strcmp("specpower", e->s_tmp) == 0)
		e->y_atb.specpower++;
	else if (ft_strcmp("angle", e->s_tmp) == 0)
		e->y_atb.angle++;
	else if (ft_strcmp("rotate", e->s_tmp) == 0)
		e->y_atb.rotate++;
	else if (ft_strcmp("translate", e->s_tmp) == 0)
		e->y_atb.translate++;
	else if (ft_strcmp("direction", e->s_tmp) == 0)
		e->y_atb.direction++;
	else
		return (57);
	return (0);
}

int		shapevocab_checker_plane(t_env *e)
{
	if (ft_strcmp("normal", e->s_tmp) == 0)
		e->p_atb.normal++;
	else if (ft_strcmp("d", e->s_tmp) == 0)
		e->p_atb.d++;
	else if (ft_strcmp("diffusion", e->s_tmp) == 0)
		e->p_atb.diffusion++;
	else if (ft_strcmp("reflection", e->s_tmp) == 0)
		e->p_atb.reflection++;
	else if (ft_strcmp("specvalue", e->s_tmp) == 0)
		e->p_atb.specvalue++;
	else if (ft_strcmp("specpower", e->s_tmp) == 0)
		e->p_atb.specpower++;
	else if (ft_strcmp("rotate", e->s_tmp) == 0)
		e->p_atb.rotate++;
	else if (ft_strcmp("translate", e->s_tmp) == 0)
		e->p_atb.translate++;
	else
		return (58);
	return (0);
}

int		shapevocab_checker(t_env *e, char **split_test)
{
	int	ret;

	ret = 0;
	e->s_tmp = ft_strsub(split_test[0], 4,
		(ft_strclen(split_test[0], '>') - 4));
	if (e->p.current_shape == 1)
		if ((ret = shapevocab_checker_shpere(e)) != 0)
			return (ret);
	if (e->p.current_shape == 2)
		if ((ret = shapevocab_checker_cone(e)) != 0)
			return (ret);
	if (e->p.current_shape == 3)
		if ((ret = shapevocab_checker_cyn(e)) != 0)
			return (ret);
	if (e->p.current_shape == 4)
		if ((ret = shapevocab_checker_plane(e)) != 0)
			return (ret);
	free(e->s_tmp);
	e->s_tmp = NULL;
	return (0);
}
