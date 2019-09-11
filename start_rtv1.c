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
	t_ol 	*omp;
	int		i = 1;

	tmp = NULL;
	tmp = e->ll_lit;
	omp = NULL;
	omp = e->ll_obj;
	printf("\nCAMERA :\n");
	printf("position -> x : [%d] - y : [%d] - z : [%d] === ", e->cam.campos.x, e->cam.campos.y, e->cam.campos.z );
	printf("direction -> x : [%d] - y : [%d] - z : [%d] \n\n", e->cam.camdir.x, e->cam.camdir.y, e->cam.camdir.z );

	printf("AMBIANCE :\n");
	printf("specpower -> value [%d]] === ", e->amb.specpower);
	printf("color -> x : [%d] - y : [%d] - z : [%d] \n\n", e->amb.col.x, e->amb.col.y, e->amb.col.z );

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
	printf("\n\n");
	i = 1;
	while (omp)
	{
		printf("ind : [%d] ---> ", i);
		if (omp->cur_shape == 1)
			printf("SPHERE !\n");
		if (omp->cur_shape == 2)
			printf("CONE !\n");
		if (omp->cur_shape == 3)
			printf("CYLINDER !\n");
		if (omp->cur_shape == 4)
			printf("PLANE !\n");
		printf("CENTER    ---> x : [%d] - y : [%d] - z : [%d]\n", omp->cen.x, omp->cen.y, omp->cen.z);
		printf("DIRECTION ---> x : [%d] - y : [%d] - z : [%d]\n", omp->dir.x, omp->dir.y, omp->dir.z);
		printf("DIFFUSION ---> x : [%d] - y : [%d] - z : [%d]\n", omp->dif.x, omp->dif.y, omp->dif.z);
		printf("ROTATION  ---> x : [%d] - y : [%d] - z : [%d]\n", omp->rot.x, omp->rot.y, omp->rot.z);
		printf("NORMAL 	  ---> x : [%d] - y : [%d] - z : [%d]\n", omp->nor.x, omp->nor.y, omp->nor.z);
		printf("TRANSLATE ---> x : [%d] - y : [%d] - z : [%d]\n", omp->tra.x, omp->tra.y, omp->tra.z);
		printf("RADIUS    ---> [%d]\n", omp->radius);
		printf("ANGLE     ---> [%d]\n", omp->angle);
		printf("SPECVALUE ---> [%d]\n", omp->specvalue);
		printf("REFLECT   ---> [%d]\n", omp->ref);
		printf("SPECPOWER ---> [%d]\n", omp->specpower);
		printf("D-plane   ---> [%d]\n", omp->d);
		printf("STATUS    ---> [%d]\n\n", omp->status);
		omp = omp->next;
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
