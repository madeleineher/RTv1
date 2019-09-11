/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rtv1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:55:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 14:28:32 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

void	temp_function_print_data(t_env *e)	
{
	t_ll 	*tmp;
	int		i = 1;

	tmp = NULL;
	tmp = e->ll_lit;
	printf("CAMERA :\n");
	printf("position -> x : [%d] - y : [%d] - z : [%d] === ", e->cam.campos.x, e->cam.campos.y, e->cam.campos.z );
	printf("direction -> x : [%d] - y : [%d] - z : [%d] \n", e->cam.camdir.x, e->cam.camdir.y, e->cam.camdir.z );

	printf("LIGHT: \n");
	while (tmp)
	{
		printf("i : [%d] -- pos -> x : [%d] - y : [%d] - z : [%d] === ", i, tmp->pos.x, tmp->pos.y, tmp->pos.z);
		printf("ints -> x : [%d] - y : [%d] - z : [%d] === ", tmp->its.x, tmp->its.y, tmp->its.z);
		printf("rot -> x : [%d] - y : [%d] - z : [%d] === ", tmp->rot.x, tmp->rot.y, tmp->rot.z);
		printf("tra -> x : [%d] - y : [%d] - z : [%d] \n", tmp->tra.x, tmp->tra.y, tmp->tra.z);
		tmp = tmp->next;
		i++;
	}
}

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
	temp_function_print_data(e);
}
