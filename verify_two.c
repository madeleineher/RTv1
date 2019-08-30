/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:45:36 by mhernand          #+#    #+#             */
/*   Updated: 2019/08/29 15:45:38 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/rtv1.h"

// VERIFICATION OF SPHERE, CONE, CYLINDER, PLANE ++++++++++++++++++++++

void	count_shapes(t_env *e, char *split) // just to count my shapes, might not be necessary
{
	e->p.tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
		e->count.spheres++;
	else if (ft_strcmp("cone", e->p.tmp) == 0)
		e->count.cones++;
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
		e->count.cylinders++;
	else if (ft_strcmp("plane", e->p.tmp) == 0)
		e->count.planes++;
	free(e->p.tmp);
	e->p.tmp = NULL;
}

int		verifyobjecttags_openings(t_env *e, char **split)
{
	e->p.tmp = ft_strsub(split[0], 3, (ft_strlen(split[0]) - 3));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		e->p_obj.sphere += 1;
		e->p.current_shape = 1;
		if (ft_iseven(e->p_obj.sphere) == 0)
			return (30);
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		e->p_obj.cone += 1;
		e->p.current_shape = 2;
		if (ft_iseven(e->p_obj.cone) == 0)
			return (31);
	}
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		e->p_obj.cylinder += 1;
		e->p.current_shape = 3;
		if (ft_iseven(e->p_obj.cylinder) == 0)
			return (32);
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		e->p_obj.plane += 1;
		e->p.current_shape = 4;
		if (ft_iseven(e->p_obj.plane) == 0)
			return (33);
	}
	else
		return (20);
	return (0);
}

int		verifyobjecttags_closings_brackets(t_env *e, char *split) // ++
{
	if (split[2] != '<' && split[3] != '/' && split[ft_strlen(split) - 1] != '>')
		return (21);
	e->p.close_obj_i = -1;
	e->p.good_obj_brack = 0;
	e->p.bad_obj_brack = 0;
	while (split[++e->p.close_obj_i])
	{
		if (split[e->p.close_obj_i] == '<' && split[e->p.close_obj_i + 1] == '/')
			e->p.good_obj_brack++;
		if (split[e->p.close_obj_i] == '>' && split[e->p.close_obj_i + 1] == '\0')
			e->p.good_obj_brack++;
		if (split[e->p.close_obj_i] == '<' && split[e->p.close_obj_i + 1] != '/')
			e->p.bad_obj_brack++;
		if (split[e->p.close_obj_i] == '>' && split[e->p.close_obj_i + 1] != '\0')
			e->p.bad_obj_brack++;
	}
	if (e->p.good_obj_brack != 2 || e->p.bad_obj_brack > 0)
		return (21);
	return (0);
}

int		checkforopenobjecttags(t_env *e)
{
	/*
		checks to see if there is conflicting object tags
		for example if a cone is interferring with a sylinder tag.
	*/
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p_obj.cone) == -1 || ft_iseven(e->p_obj.cylinder) == -1 || ft_iseven(e->p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p_obj.sphere) == -1 || ft_iseven(e->p_obj.cylinder) == -1 || ft_iseven(e->p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("cylinder", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p_obj.sphere) == -1 || ft_iseven(e->p_obj.cone) == -1 || ft_iseven(e->p_obj.plane) == -1)
			return (-1);
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		if (ft_iseven(e->p_obj.sphere) == -1 || ft_iseven(e->p_obj.cone) == -1 || ft_iseven(e->p_obj.cylinder) == -1)
			return (-1);
	}
	return (0);
}

void	reset_shape_atb(t_env *e)
{
	e->s_atb.radius = 0;
	e->s_atb.center = 0;
	e->s_atb.diffusion = 0;
	e->s_atb.reflection = 0;
	e->s_atb.specpower = 0;
	e->s_atb.specvalue = 0;
	e->s_atb.rotate = 0;
	e->s_atb.translate = 0;

	e->c_atb.radius = 0;
	e->c_atb.center = 0;
	e->c_atb.diffusion = 0;
	e->c_atb.reflection = 0;
	e->c_atb.specpower = 0;
	e->c_atb.specvalue = 0;
	e->c_atb.angle = 0;
	e->c_atb.rotate = 0;
	e->c_atb.translate = 0;
	e->c_atb.direction = 0;

	e->y_atb.radius = 0;
	e->y_atb.center = 0;
	e->y_atb.diffusion = 0;
	e->y_atb.reflection = 0;
	e->y_atb.specpower = 0;
	e->y_atb.specvalue = 0;
	e->y_atb.angle = 0;
	e->y_atb.rotate = 0;
	e->y_atb.translate = 0;
	e->y_atb.direction = 0;

	e->p_atb.normal = 0;
	e->p_atb.d = 0;
	e->p_atb.diffusion = 0;
	e->p_atb.reflection = 0;
	e->p_atb.specpower = 0;
	e->p_atb.specvalue = 0;
	e->p_atb.rotate = 0;
	e->p_atb.translate = 0;

}

int		verifyobjecttags_closings(t_env *e, char *split)
{
	int	ret_obj;

	ret_obj = 0;
	e->p.tmp = ft_strsub(split, 4, (ft_strlen(split) - 5));
	if (ft_strcmp("sphere", e->p.tmp) == 0)
	{
		open_close(&e->p_obj.sphere);
		if (ft_iseven(e->p_obj.sphere) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		reset_shape_atb(e);
	}
	else if (ft_strcmp("cone", e->p.tmp) == 0)
	{
		open_close(&e->p_obj.cone);
		if (ft_iseven(e->p_obj.cone) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		reset_shape_atb(e);
	}
	else if (ft_strcmp("cylinder", e->p.tmp) == 0) // here now !
	{
		open_close(&e->p_obj.cylinder);
		if (ft_iseven(e->p_obj.cylinder) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		reset_shape_atb(e);
	}
	else if (ft_strcmp("plane", e->p.tmp) == 0)
	{
		open_close(&e->p_obj.plane);
		if (ft_iseven(e->p_obj.plane) == -1)
			return (34);
		if ((checkforopenobjecttags(e)) == -1)
			return (38);
		if ((ret_obj = shapevocab_checker_partwo(e)) != 0)
			return (ret_obj);
		// printf("objects CLOSING int ===> sphere : [%d] cone : [%d] cyn : [%d] plane : [%d]\n", e->p_obj.sphere, e->p_obj.cone, e->p_obj.cylinder, e->p_obj.plane);		
		reset_shape_atb(e);
	}
	else
		return (20);
	return (0);
}

int		twotab_verifications(t_env *e, char **split_test) // SHAPES START VERIFIER ++
{
	if (e->str_count == 4)
	{
		if ((e->ret_tmp = verifyobjecttags_openings(e, split_test)) != 0) //////////// working here !!!!!!!!!!!!!!!!!!!!!!!!!!
			return (e->ret_tmp);
		if ((e->ret_tmp = two_angle_brackets(e)) != 2) 
			return (9);
		if ((e->ret_tmp = extract_status(e, split_test)) != 0)
			return (e->ret_tmp);
	}
	else if (e->str_count == 1)
	{
		if ((e->ret_tmp = verifyobjecttags_closings_brackets(e, split_test[0])) != 0)
			return (e->ret_tmp);
		if ((e->ret_tmp = verifyobjecttags_closings(e, split_test[0])) != 0) // here too !
			return (e->ret_tmp);
		count_shapes(e, split_test[0]);
	}
	else if (e->str_count != 1 || e->str_count != 4)
		return (13);
	return (0);
}