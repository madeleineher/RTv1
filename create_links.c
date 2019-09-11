/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:36:14 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/10 18:36:26 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

int		add_link_light(t_env *e, t_ll **head, t_ll *ll_savehead)
{
	// printf("printing pos X --> [%d]\n", &(*head)->pos.x);
	(void)e;
	t_ll	*new;
	t_ll	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ll*)malloc(sizeof(t_ll))))
		return (-1);
	// new->content = line;
	ft_bzero(&new->pos, sizeof(new->pos));
	ft_bzero(&new->its, sizeof(new->its));
	
	// printf("creating pos X --> [%d]\n", new->pos.x);
	// printf("int --> [%p]\n", &new->its);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		ll_savehead = *head;
		e->save_light = ll_savehead;
	}
	else
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
	return (0);
}

int		add_link_obj(t_env *e, t_ol **head)
{
	(void)e;
	t_ol	*new;
	t_ol	*last;

	last = *head;
	new = NULL;
	if (!(new = (t_ol*)malloc(sizeof(t_ol))))
		return (-1);
	// new->content = line;
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
