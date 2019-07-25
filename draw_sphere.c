/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:40:45 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/25 17:40:47 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void    draw_sphere(t_env *e)
{
    int     px = ft_atoi(e->s.params[0]);
    int     py = ft_atoi(e->s.params[1]);
    double  rad = (double)ft_atoi(e->s.params[2]);
    (void)e, (void)px, (void)py, (void)rad;
}