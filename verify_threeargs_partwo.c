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

int		verify_numbers_three(t_env *e, char *string) // working here 
{
	// printf("[%d] [%d] [%d]\n", e->p.v1, e->p.v2, e->p.v3); // working here
	if (ft_strcmp("direction", string) == 0)
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
                
            }
		}
        if (e->p.specs == 2 && e->p.objects == 1) // in the objects tag <objects> </objects>
		{
            if (e->p.current_shape == 0 || e->p.current_shape == 1 || e->p.current_shape == 2)
            {
                
            }
		}
	}
	else if (ft_strcmp("axis", string) == 0)
	{
		
	}
	else if (ft_strcmp("center", string) == 0)
	{
		
	}
	else if (ft_strcmp("normal", string) == 0) 
	{
		if ((e->p.ret_p = verify_values(e)) != 0)
			return (85);
	}
	else if (ft_strcmp("diffusion", string) == 0)
	{
		
	}
	else if (ft_strcmp("rotate", string) == 0)
	{
		
	}
	else if (ft_strcmp("translate", string) == 0)
	{
		
	}
	else if (ft_strcmp("position", string) == 0)
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
	else if (ft_strcmp("color", string) == 0)
	{
		
	}
	else if (ft_strcmp("intensity", string) == 0)
	{
		
	}
	return (0);
}