/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:01:20 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/30 14:43:03 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int	whatami(t_env *e, char *)
{
	if (ft_strcmp(e->whatami, AMB"))
		setupambience(e);
	else if (ft_strcmp(e->whatami, "CAM"))
		setupcam(e);
	else if (ft_strcmp(e->whatami, "CONE"))
		setupcone(e);
	else if (ft_strcmp(e->whatami, "CYLINDER"))
		setupcyn(e);
	else if (ft_strcmp(e->whatami, "LIGHT"))
		setuplight(e);
	else if (ft_strcmp(e->whatami, "PLANE"))
		setuplane(e);
	else if (ft_strcmp(e->whatami, "SPHERE"))
		setupsphere(e);
	else
		return (-1);
	return (0);
}

int	add_link(char **line, t_ll *head)
{
	t_ll	*new;
	t_ll	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	new->content = line;
	new->next = NULL;
	if (*head != NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (0);
}

int	parser(t_env *e)
{
	int	ret;
	char	*gnl_line;

	ret = 0;
	gnl_line = NULL;
	while ((ret = get_next_line(fd, &gnl_line)) > 0)
	{
		e->lines = ft_strsplit(gnl_line, ':');
		if ((add_link(e->lines, &head)) == -1)
			return (-1);
		if (gnl_line)
		{
			free(gnl_line);
			gnl_line = NULL;
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}
