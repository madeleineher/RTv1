/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_specs_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:04:48 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/05 11:04:50 by mhernand         ###   ########.fr       */
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

int		verify_light(t_env *e, char **split_test)
{
	int	ret;

	ret = 0;
	e->p_spec.light += 1;
	if (ft_iseven(e->p_spec.light) == 0)
		return (12);
	if ((ret = extract_status(e, split_test)) != 0)
		return (ret);
	return (ret);
}

int		verifyspectags_openings(t_env *e, char **split)
{
	e->p.tmp = ft_strsub(split[0], 2, (ft_strlen(split[0]) - 2));
	if (ft_strcmp("<cam>", e->p.tmp) == 0)
	{
        if (e->p_spec.amb_cl > 0)
            return (28);
		e->p_spec.cam += 1;
	}
	else if (ft_strcmp("<amb>", e->p.tmp) == 0)
	{
        if (e->p_spec.cam_cl != 1)
            return (28);
		e->p_spec.amb += 1;
	}
	else if (ft_strcmp("<light", e->p.tmp) == 0)
    {
        if ((e->ret_tmp = verify_light(e, split)) != 0)
            return (e->ret_tmp);
    }
	else
		return (8); // mlx error
    free(e->p.tmp);
    e->p.tmp = NULL;
	return (0);
}

int		verifyspectags_closing(t_env *e, char **split)
{
	int		ret;

	ret = 0;
	if (e->p_spec.cam == 1)
	{
		if ((ret = ft_strcmp("\t\t</cam>", split[0]) != 0))
			return (10);
		open_close(&e->p_spec.cam);
        e->p_spec.cam_cl++;
        if ((e->ret_tmp = verify_spec_atb_partwo(e)) != 0)
            return(e->ret_tmp);
		reset_spec_atb(e);
	}
	else if (e->p_spec.amb == 1)
	{
        
		if ((ret = ft_strcmp("\t\t</amb>", split[0])) != 0)
			return (11);
		open_close(&e->p_spec.amb);
        e->p_spec.amb_cl++;
        if ((e->ret_tmp = verify_spec_atb_partwo(e)) != 0)
            return(e->ret_tmp);
		reset_spec_atb(e);
	}
	else if (e->p_spec.light >= 1)
	{
		if ((ret = ft_strcmp("\t\t</light>", split[0])) != 0)
			return (12);
		open_close(&e->p_spec.light);
		if (ft_iseven(e->p_spec.light) == -1)
			return (29);
        if ((e->ret_tmp = verify_spec_atb_partwo(e)) != 0)
            return(e->ret_tmp);
		reset_spec_atb(e);
	}
	return (0);
}

int		two_tabs_specs(t_env *e, char **split_test)
{
	int	ret_tmp;

	ret_tmp = 0;
	if ((ret_tmp = two_angle_brackets(e)) != 2)
		return (9);
	if (ft_strclen(e->p.gnl_line, '/') == 0)
	{
        if ((ret_tmp = verifyspectags_openings(e, split_test)) != 0)
            return (ret_tmp);
	}
	else if (ft_strclen(e->p.gnl_line, '/') > 0)
	{
		if ((ret_tmp = verifyspectags_closing(e, split_test)) != 0)
			return (ret_tmp);
	}			
	else if (e->str_count != 1 || e->str_count != 4)
		return (13);
	return (0);
}
