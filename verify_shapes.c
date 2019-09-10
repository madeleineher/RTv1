/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:45:36 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/03 13:29:59 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

// VERIFICATION OF SPHERE, CONE, CYLINDER, PLANE

void	count_shapes(t_env *e, char *split)
{
	e->p.tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
		e->p.count.spheres++;
	else if (ft_strcmp("cone", e->p.tmp) == 0)
		e->p.count.cones++;
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
		e->p.count.cylinders++;
	else if (ft_strcmp("plane", e->p.tmp) == 0)
		e->p.count.planes++;
	free(e->p.tmp);
	e->p.tmp = NULL;
}

int		verifyobjecttags_openings(t_env *e, char **split) // /! string needs to be freed before returning error message /!
{
	e->p.tmp = ft_strsub(split[0], 3, (ft_strlen(split[0]) - 3));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		e->p.p_obj.sphere += 1;
		e->p.current_shape = 1;
		if (ft_iseven(e->p.p_obj.sphere) == 0)
		{
			free(e->p.tmp);
			e->p.tmp = NULL;
			return (30);
		}
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		e->p.p_obj.cone += 1;
		e->p.current_shape = 2;
		if (ft_iseven(e->p.p_obj.cone) == 0)
		{
			free(e->p.tmp);
			e->p.tmp = NULL;
			return (31);
		}
	}
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		e->p.p_obj.cyn += 1;
		e->p.current_shape = 3;
		if (ft_iseven(e->p.p_obj.cyn) == 0)
		{
			free(e->p.tmp);
			e->p.tmp = NULL;
			return (32);
		}
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		e->p.p_obj.plane += 1;
		e->p.current_shape = 4;
		if (ft_iseven(e->p.p_obj.plane) == 0)
		{
			free(e->p.tmp);
			e->p.tmp = NULL;
			return (33);
		}
	}
	else
	{
		free(e->p.tmp);
		e->p.tmp = NULL;
		return (20);
	}
	free(e->p.tmp);
	e->p.tmp = NULL;
	return (0);
}

int		verifyobjecttags_closings_brackets(t_env *e, char *str)
{
	if (str[2] != '<' && str[3] != '/' && str[ft_strlen(str) - 1] != '>')
		return (21);
	e->p.close_obj_i = -1;
	e->p.good_obj_brack = 0;
	e->p.bad_obj_brack = 0;
	while (str[++e->p.close_obj_i])
	{
		if (str[e->p.close_obj_i] == '<' && str[e->p.close_obj_i + 1] == '/')
			e->p.good_obj_brack++;
		if (str[e->p.close_obj_i] == '>' && str[e->p.close_obj_i + 1] == '\0')
			e->p.good_obj_brack++;
		if (str[e->p.close_obj_i] == '<' && str[e->p.close_obj_i + 1] != '/')
			e->p.bad_obj_brack++;
		if (str[e->p.close_obj_i] == '>' && str[e->p.close_obj_i + 1] != '\0')
			e->p.bad_obj_brack++;
	}
	if (e->p.good_obj_brack != 2 || e->p.bad_obj_brack > 0)
		return (21);
	return (0);
}

int		checkforopenobjecttags(t_env *e)
{
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.cone) == -1 || ft_iseven(e->p.p_obj.cyn) == -1
				|| ft_iseven(e->p.p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.sphere) == -1 || ft_iseven(e->p.p_obj.cyn) == -1
				|| ft_iseven(e->p.p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.sphere) == -1 || ft_iseven(e->p.p_obj.cone) == -1
				|| ft_iseven(e->p.p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p.p_obj.sphere) == -1 || ft_iseven(e->p.p_obj.cone) == -1
			   || ft_iseven(e->p.p_obj.cyn) == -1)
			return (-1);
	}
	return (0);
}

void	reset_shape_atb_part_two(t_env *e)
{
	e->p.y_atb.radius = 0;
	e->p.y_atb.center = 0;
	e->p.y_atb.diffusion = 0;
	e->p.y_atb.reflection = 0;
	e->p.y_atb.specpower = 0;
	e->p.y_atb.specvalue = 0;
	e->p.y_atb.angle = 0;
	e->p.y_atb.rotate = 0;
	e->p.y_atb.translate = 0;
	e->p.y_atb.direction = 0;
	e->p.p_atb.normal = 0;
	e->p.p_atb.d = 0;
	e->p.p_atb.diffusion = 0;
	e->p.p_atb.reflection = 0;
	e->p.p_atb.specpower = 0;
	e->p.p_atb.specvalue = 0;
	e->p.p_atb.rotate = 0;
	e->p.p_atb.translate = 0;
}

void	reset_shape_atb(t_env *e)
{
	e->p.s_atb.radius = 0;
	e->p.s_atb.center = 0;
	e->p.s_atb.diffusion = 0;
	e->p.s_atb.reflection = 0;
	e->p.s_atb.specpower = 0;
	e->p.s_atb.specvalue = 0;
	e->p.s_atb.rotate = 0;
	e->p.s_atb.translate = 0;
	e->p.c_atb.radius = 0;
	e->p.c_atb.center = 0;
	e->p.c_atb.diffusion = 0;
	e->p.c_atb.reflection = 0;
	e->p.c_atb.specpower = 0;
	e->p.c_atb.specvalue = 0;
	e->p.c_atb.angle = 0;
	e->p.c_atb.rotate = 0;
	e->p.c_atb.translate = 0;
	e->p.c_atb.direction = 0;
	reset_shape_atb_part_two(e);
}

int		verifyobjecttags_closings(t_env *e, char *split)
{
	int	ret_obj;

	ret_obj = 0;
	e->p.tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.sphere);
		if (ft_iseven(e->p.p_obj.sphere) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		reset_shape_atb(e);
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.cone);
		if (ft_iseven(e->p.p_obj.cone) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		reset_shape_atb(e);
	}
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.cyn);
		if (ft_iseven(e->p.p_obj.cyn) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		reset_shape_atb(e);
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		open_close(&e->p.p_obj.plane);
		if (ft_iseven(e->p.p_obj.plane) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		reset_shape_atb(e);
	}
	else
		return (20);
	return (0);
}

int		twotab_verifications(t_env *e)
{
	if (e->str_count == 4)
	{
		if ((e->p.ret_p = verifyobjecttags_openings(e, e->p.split)) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = two_angle_brackets(e)) != 2) 
			return (9);
		if ((e->p.ret_p = extract_status(e)) != 0)
			return (e->p.ret_p);
	}
	else if (e->str_count == 1)
	{
		if ((e->p.ret_p = verifyobjecttags_closings_brackets(e, e->p.split[0])) != 0)
			return (e->p.ret_p);
		if ((e->p.ret_p = verifyobjecttags_closings(e, e->p.split[0])) != 0)
			return (e->p.ret_p);
		count_shapes(e, e->p.split[0]);
	}
	else if (e->str_count != 1 || e->str_count != 4)
		return (13);
	return (0);
}
