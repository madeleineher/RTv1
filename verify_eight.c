/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_eight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:29:56 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/03 16:29:57 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int     verify_spec_atb(t_env *e, char **split_test)
{
    e->s_tmp = ft_strsub(split_test[0], 4,
		(ft_strclen(split_test[0], '>') - 4));
    // if (e->spcs.cam == 1)
    // {
    //     printf("str[%s]\n", e->s_tmp);
    //     if (ft_strcmp("position", e->s_tmp) == 0)
    //         e->ca_atb.position++;
    //     else if (ft_strcmp("direction", e->s_tmp) == 0)
    //         e->ca_atb.direction++;
    //     // else
    //         // return (64); // change msg // fucking up here !
    // }
    // if (e->p.spec_order == 1)
    // {
    //     if (ft_strcmp("specpower", e->s_tmp) == 0)
    //         e->a_atb.power++;
    //     else if (ft_strcmp("color", e->s_tmp) == 0)
    //         e->a_atb.color++;
    //     else
    //         return (65); // change msg
    // }
    // if (e->p.spec_order > 1)
    // {
    //     if (ft_strcmp("postion", e->s_tmp) == 0)
    //         e->l_atb.position++;
    //     else if (ft_strcmp("intesity", e->s_tmp) == 0)
    //         e->l_atb.intensity++;
    //     // else if (ft_strcmp("rotation", e->s_tmp) == 0)
    //     //     e->l_atb.rotate++;
    //     // else if (ft_strcmp("translatino", e->s_tmp) == 0)
    //     //     e->l_atb.translate++;
    //     else
    //         return (66); // change msg
    // }
    free(e->s_tmp);
	e->s_tmp = NULL;
    return (0);
}

int		verify_spec_atb_partwo(t_env *e)
{
    (void)e;
    // if (e->spcs.cam == 1)
    // {
        // if (e->ca_atb.position < 1 || e->ca_atb.direction < 1)
            // return (60); // change msg
        // if (e->ca_atb.position > 1 || e->ca_atb.direction > 1)
            // return (61);
        // if (e->p.status == 1)
        //     if (e->s_atb.rotate != 0 || e->s_atb.translate != 0)
        //         return (41);
        // if (e->p.status == 2)
        //     if (e->s_atb.rotate != 1 || e->s_atb.translate != 1)
        //         return (42);
    // }
    // if (e->p.spec_order == 2)
    // {
    //     if (e->a_atb.power < 1 || e->a_atb.color < 1)
    //         return (62); // change msg
    //     if (e->a_atb.power > 1 || e->a_atb.color > 1)
    //         return (63);
    //     // if (e->p.status == 1)
    //     //     if (e->s_atb.rotate != 0 || e->s_atb.translate != 0)
    //     //         return (41);
    //     // if (e->p.status == 2)
    //     //     if (e->s_atb.rotate != 1 || e->s_atb.translate != 1)
    //     //         return (42);
    // }
    // if (e->p.spec_order >= 3)
    // {
    //     if (e->l_atb.position < 1 || e->l_atb.intensity < 1)
    //         return (39); // change msg
    //     if (e->l_atb.position > 1 || e->l_atb.intensity > 1)
    //         return (40);
    //     if (e->p.status == 1)
    //         if (e->l_atb.rotate != 0 || e->l_atb.translate != 0)
    //             return (41);
    //     if (e->p.status == 2)
    //         if (e->l_atb.rotate != 1 || e->l_atb.translate != 1)
    //             return (42);
    // }
	return (0);
}

// fix this whole file !