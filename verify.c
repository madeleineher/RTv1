/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/31 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int	howmanystrings(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);	
}

char	*getnumber(char *split)
{
	while (!ft_isdigit(*split))
		split++;
	return (split);
}

int	verify(t_env *e, char *whatami)
{
	int	ret;
	char	**splits = NULL;

	ret = 0;
	e->i = -1;
	splits = ft_strsplit(e->line[1], ';');
	if (ft_strcmp(whatami, "AMB") == 0) // DONE !
	{
		ret = verifyamb(e, splits);
		printf("AMBIANCE\n");
		printf("==>%s<== | -->%d %d %d<--\n", splits[0], e->amb.diff->x, e->amb.diff->y, e->amb.diff->z);
		printf("==>%s<== | -->%d %d %d<--\n", splits[1], e->amb.ref->x, e->amb.ref->y, e->amb.ref->z);
		printf("==>%s<== | -->%d<--\n", splits[2], e->amb.specvalue);
		printf("==>%s<== | -->%d<--\n", splits[3], e->amb.specpower);
	}
	else if (ft_strcmp(whatami, "CAM") == 0)
	{
		ret = verifycam(e, splits);
		printf("CAMERA\n");
		printf("==>%s<== | -->%d %d %d<--\n", splits[0], e->cam.campos->x, e->cam.campos->y, e->cam.campos->z);
		printf("==>%s<== | -->%d %d %d<--\n", splits[1], e->cam.camdir->x, e->cam.camdir->y, e->cam.camdir->z);
	}
	else if (ft_strcmp(whatami, "CONE") == 0)
	{
		ret = verifycone(e, splits);
		printf("CONE\n");
		printf("==>%s<== | -->%d %d %d<--\n", splits[0], e->cone.dir->x, e->cone.dir->y, e->cone.dir->z);
		printf("==>%s<== | -->%d %d %d<--\n", splits[1], e->cone.cen->x, e->cone.cen->y, e->cone.cen->z);
		printf("==>%s<== | -->%d<--\n", splits[2], e->cone.angle);
		printf("==>%s<== | -->%d<--\n", splits[3], e->cone.ambient);
	}
	else if (ft_strcmp(whatami, "CYLINDER") == 0)
	{
		ret = verifycyn(e, splits);
		printf("CYLINDER\n");
		printf("==>%s<== | -->%d %d %d<--\n", splits[0], e->cyn.dir->x, e->cyn.dir->y, e->cyn.dir->z);
		printf("==>%s<== | -->%d<--\n", splits[1], e->cyn.axis);
		printf("==>%s<== | -->%d<--\n", splits[2], e->cyn.radius);
		printf("==>%s<== | -->%d<--\n", splits[3], e->cyn.ambient);
	}
	else if (ft_strcmp(whatami, "LIGHT") == 0)
	{
		ret = verifylight(e, splits);
		printf("LIGHTS\n");
		printf("==>%s<== | -->%d %d %d<--\n", splits[0], e->light.lipos->x, e->light.lipos->y, e->light.lipos->z);
		printf("==>%s<== | -->%d %d %d<--\n", splits[1], e->light.inten->x, e->light.inten->y, e->light.inten->z);
	}
	else if (ft_strcmp(whatami, "PLANE") == 0)
	{
		ret = verifyplane(e, splits);
		printf("PLANE\n");
		printf("==>%s<== | -->%d %d %d<--\n", splits[0], e->plane.nor->x, e->plane.nor->y, e->plane.nor->z);
		printf("==>%s<== | -->%d<--\n", splits[1], e->plane.d);
		printf("==>%s<== | -->%d<--\n", splits[2], e->plane.mat);
	}
	else if (ft_strcmp(whatami, "SPHERE") == 0)
	{
		ret = verifysphere(e, splits);
		printf("SPHERE\n");
		printf("==>%s<== | -->%d %d %d<--\n", splits[0], e->sphere.cen->x, e->sphere.cen->y, e->sphere.cen->z);
		printf("==>%s<== | -->%d<--\n", splits[1], e->sphere.radius);
		printf("==>%s<== | -->%d<--\n", splits[2], e->sphere.ambient);
	}
	if (ret == -1)
		return (-1);
	return (0);
}
