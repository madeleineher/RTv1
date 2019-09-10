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

int		verify_numbers_one(t_env *e, char *string, char *num) // working here !
{
	e->p.realnum = ft_atoi(num);
	if (ft_strcmp("radius", string) == 0)
	{
		if (e->p.realnum <= 0) // || e->p.realnum > LIMIT (?))
			return (83);
		if (e->p.specs == 2 && e->p.objects == 1) // in the objects tag <objects> </objects>
		{
            if (e->p.current_shape == 0 || e->p.current_shape == 1 || e->p.current_shape == 2)
            {
                
            }
		}
		// store value here based on object (spec/shape) ... 
	}
	else if (ft_strcmp("angle", string) == 0)
	{
		if (e->p.realnum > 360 || e->p.realnum < -360)
			return (84);
		// store value here			
	}
	else if (ft_strcmp("d", string) == 0)
	{
		// store value here		
	}
	else if (ft_strcmp("specpower", string) == 0)
	{
		// store value here		
	}
	else if (ft_strcmp("specvalue", string) == 0)
	{
		// store value here		
	}
	else if (ft_strcmp("reflection", string) == 0)
	{
		// store value here		
	}
	return (0);
}