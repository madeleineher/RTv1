/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rtv1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:55:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/25 15:55:10 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/rtv1.h"

void    start_rtv1(t_env *e)
{
        mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
        mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
        mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
        // mlx_hook(e->w.wp, 6, 1L << 6, mouse_move, e);
        // mlx_hook(e->w.wp, 4, 1L << 4, mouse_click, e);
        // mlx_hook(e->w.wp, 5, 1L << 5, mouse_no_click, e);
        mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
        mlx_loop_hook(e->w.mp, touch, e);
}