/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_threeargs_partwo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:15 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 11:10:16 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		verify_values(t_env *e)
{
	if (e->p.v1 == 0 && e->p.v2 == 0 && e->p.v3 == 0)
		return (85);
    return (0);
}

int		verify_numbers_three(t_env *e, t_ll *l_head, t_ol *o_head) // working here 
{
	// printf("[%d] [%d] [%d]\n", e->p.v1, e->p.v2, e->p.v3); // working here
    (void)o_head;
    (void)l_head;
    //add_link
	if (ft_strcmp("direction", e->p.strtwo) == 0)
	{
		if ((e->p.ret_p = verify_values(e)) != 0)
			return (85);
        if (e->p.specs == 1 && e->p.objects == 0) // in the specs tag <specs> </specs>
		{
			if (e->p.p_spec.cam == 1 && e->p.p_spec.amb_cl == 0) // cam position
            {
                e->cam.camdir.x = e->p.v1;
                e->cam.camdir.y = e->p.v2;
                e->cam.camdir.z = e->p.v3;
            }
            else if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1) // light position
            {
                //in light

            }
		}
        if (e->p.specs == 2 && e->p.objects == 1) // in the objects tag <objects> </objects>
		{
            if (e->p.current_shape == 0 || e->p.current_shape == 1 || e->p.current_shape == 2)
            {
                
            }
		}
	}
	else if (ft_strcmp("axis", e->p.strtwo) == 0)
	{
		
	}
	else if (ft_strcmp("center", e->p.strtwo) == 0)
	{
		
	}
	else if (ft_strcmp("normal", e->p.strtwo) == 0) 
	{
		if ((e->p.ret_p = verify_values(e)) != 0)
			return (85);
	}
	else if (ft_strcmp("diffusion", e->p.strtwo) == 0)
	{
		
	}
	else if (ft_strcmp("rotate", e->p.strtwo) == 0)
	{
		
	}
	else if (ft_strcmp("translate", e->p.strtwo) == 0)
	{
		
	}
	else if (ft_strcmp("position", e->p.strtwo) == 0)
	{
        if (e->p.specs == 1 && e->p.objects == 0) // in the specs tag <specs> </specs>
		{
			if (e->p.p_spec.cam == 1 && e->p.p_spec.amb_cl == 0) // cam position
            {
                e->cam.campos.x = e->p.v1;
                e->cam.campos.y = e->p.v2;
                e->cam.campos.z = e->p.v3;
            }
            else if (e->p.p_spec.cam_cl == 1 && e->p.p_spec.amb_cl == 1) // light position
            {

            }
		}
	}
	else if (ft_strcmp("color", e->p.strtwo) == 0)
	{
		
	}
	else if (ft_strcmp("intensity", e->p.strtwo) == 0)
	{
		
	}
	return (0);
}