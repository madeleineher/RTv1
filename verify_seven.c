/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_seven.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:38:23 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/03 12:46:19 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		shapevocab_checker_partwo_sphere(t_env *e)
{
	if (e->s_atb.radius < 1 || e->s_atb.center < 1 || e->s_atb.diffusion < 1
			|| e->s_atb.reflection < 1 || e->s_atb.specvalue < 1
			|| e->s_atb.specpower < 1)
		return (39);
	if (e->s_atb.radius > 1 || e->s_atb.center > 1 || e->s_atb.diffusion > 1
			|| e->s_atb.reflection > 1 || e->s_atb.specvalue > 1
			|| e->s_atb.specpower > 1)
		return (40);
	if (e->p.status == 1)
		if (e->s_atb.rotate != 0 || e->s_atb.translate != 0)
			return (41);
	if (e->p.status == 2)
		if (e->s_atb.rotate != 1 || e->s_atb.translate != 1)
			return (42);
	return (0);
}

int		shapevocab_checker_partwo_cone(t_env *e)
{
	if (e->c_atb.radius < 1 || e->c_atb.center < 1 || e->c_atb.diffusion < 1
			|| e->c_atb.direction < 1 || e->c_atb.reflection < 1
			|| e->c_atb.specvalue < 1 || e->c_atb.specpower < 1
			|| e->c_atb.angle < 1)
		return (43);
	if (e->c_atb.radius > 1 || e->c_atb.center > 1 || e->c_atb.diffusion > 1
			|| e->c_atb.direction > 1 || e->c_atb.reflection > 1
			|| e->c_atb.specvalue > 1 || e->c_atb.specpower > 1
			|| e->c_atb.angle > 1)
		return (44);
	if (e->p.status == 1)
		if (e->c_atb.rotate != 0 || e->c_atb.translate != 0)
			return (45);
	if (e->p.status == 2)
		if (e->c_atb.rotate != 1 || e->c_atb.translate != 1)
			return (46);
	return (0);
}

int		shapevocab_checker_partwo_cyn(t_env *e)
{
	if (e->y_atb.radius < 1 || e->y_atb.center < 1 || e->y_atb.diffusion < 1
			|| e->y_atb.direction < 1 || e->y_atb.reflection < 1
			|| e->y_atb.specvalue < 1 || e->y_atb.specpower < 1
			|| e->y_atb.angle < 1)
		return (47);
	if (e->y_atb.radius > 1 || e->y_atb.center > 1 || e->y_atb.diffusion > 1
			|| e->y_atb.direction > 1 || e->y_atb.reflection > 1
			|| e->y_atb.specvalue > 1 || e->y_atb.specpower > 1
			|| e->y_atb.angle > 1)
		return (48);
	if (e->p.status == 1)
		if (e->y_atb.rotate != 0 || e->y_atb.translate != 0)
			return (49);
	if (e->p.status == 2)
		if (e->y_atb.rotate != 1 || e->y_atb.translate != 1)
			return (50);
	return (0);
}

int		shapevocab_checker_partwo_plane(t_env *e)
{
	if (e->p_atb.normal < 1 || e->p_atb.d < 1 || e->p_atb.diffusion < 1
			|| e->p_atb.reflection < 1 || e->p_atb.specvalue < 1
			|| e->p_atb.specpower < 1)
		return (51);
	if (e->p_atb.normal > 1 || e->p_atb.d > 1 || e->p_atb.diffusion > 1
			|| e->p_atb.reflection > 1 || e->p_atb.specvalue > 1
			|| e->p_atb.specpower > 1)
		return (52);
	if (e->p.status == 1)
		if (e->p_atb.rotate != 0 || e->p_atb.translate != 0)
			return (53);
	if (e->p.status == 2)
		if (e->p_atb.rotate != 1 || e->p_atb.translate != 1)
			return (54);
	return (0);
}

int		shapevocab_checker_partwo(t_env *e)
{
	int ret;

	ret = 0;
	if (e->p.current_shape == 1)
		if ((ret = shapevocab_checker_partwo_sphere(e)) != 0)
			return (ret);
	if (e->p.current_shape == 2)
		if ((ret = shapevocab_checker_partwo_cone(e)) != 0)
			return (ret);
	if (e->p.current_shape == 3)
		if ((ret = shapevocab_checker_partwo_cyn(e)) != 0)
			return (ret);
	if (e->p.current_shape == 4)
		if ((ret = shapevocab_checker_partwo_plane(e)) != 0)
			return (ret);
	return (0);
}
