/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_oneargs_partwo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:10:23 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 11:10:28 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		verify_numbers_one(t_env *e, t_ll *l_head, t_ol *o_head)// working here !
{
    (void)o_head;
    (void)l_head;
	e->p.v = ft_atoi(e->p.strone);
	if (ft_strcmp("radius", e->p.strtwo) == 0)
	{
		if (e->p.v <= 0) // || e->p.realnum > LIMIT (?))
			return (83);
		if (e->p.specs == 2 && e->p.objects == 1) // in the objects tag <objects> </objects>
		{
            if (e->obj.current_shape == 0 || e->obj.current_shape == 1 || e->obj.current_shape == 2)
            {
                
            }
		}
		// store value here based on object (spec/shape) ... 
	}
	else if (ft_strcmp("angle", e->p.strtwo) == 0)
	{
		if (e->p.v > 360 || e->p.v < -360)
			return (84);
		// store value here			
	}
	else if (ft_strcmp("d", e->p.strtwo) == 0)
	{
		// store value here		
	}
	else if (ft_strcmp("specpower", e->p.strtwo) == 0)
	{
		// store value here		
	}
	else if (ft_strcmp("specvalue", e->p.strtwo) == 0)
	{
		// store value here		
	}
	else if (ft_strcmp("reflection", e->p.strtwo) == 0)
	{
		// store value here		
	}
	return (0);
}