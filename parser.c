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

int	whatami(t_env *e, char *whatami)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(whatami, "AMB") == 0)
		ret = verify(e, whatami);
	else if (ft_strcmp(whatami, "CAM") == 0)
		ret = verify(e, whatami);
	else if (ft_strcmp(whatami, "CONE") == 0)
		ret = verify(e, whatami);
	else if (ft_strcmp(whatami, "CYLINDER") == 0)
		ret = verify(e, whatami);
	else if (ft_strcmp(whatami, "LIGHT") == 0)
		ret = verify(e, whatami);
	else if (ft_strcmp(whatami, "PLANE") == 0)
		ret = verify(e, whatami);
	else if (ft_strcmp(whatami, "SPHERE") == 0)
		ret = verify(e, whatami);
	else
		return (-1);
	if (ret == -1)
		return (-1);
	return (0);
}

int	add_link(char **line, t_ll **head)
{
	t_ll	*new;
	t_ll	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	new->content = line;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (0);
}

int	parser(t_env *e, int fd)
{
	int	ret;
	char	*gnl_line;
	t_ll	*head;

	ret = 0;
	gnl_line = NULL;
	while ((ret = get_next_line(fd, &gnl_line)) > 0)
	{
		e->line = ft_strsplit(gnl_line, ':');
		if (whatami(e, e->line[0]) == -1)
			return (-1);
		if ((add_link(e->line, &head)) == -1)
			return (-1);
		if (gnl_line)
		{
			free(gnl_line);
			gnl_line = NULL;
		}
	}
	if (ret == -1)
		return (-1);
	e->ll = head;
	printf("VALID!\n");
	return (0);
}
